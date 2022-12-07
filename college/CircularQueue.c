#include <stdio.h>
#include <stdlib.h>

#define size 4
int queue[size];
int front=-1, rear=-1;

void enqueueC();
int dequeueC();
void display();

void main() {
    int ch, y;
    do{
        printf("\n----Circular Queue Operations----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1:
                enqueueC();
                break;
            
            case 2:
                dequeueC();
                break;
        
            case 3:
                display();
                break;
            
            default:
                printf("invalid choice!\n");
            
        }
        
        printf("\nDo you want to continue (0/1): ");
        scanf("%d", &y);
    }while(y==1);
}




void enqueueC() {
    int e;
    if((rear+1)%size == front) {
        printf("Full/Overflow\n");
        return;
    }
    else {
        printf("Enter element to insert: ");
        scanf("%d", &e);
        rear = (rear+1)%size;
        queue[rear] = e;
    }
}

int dequeueC() {
    int e;
    if(front == -1) {
        printf("Empty/Underflow\n");
        return 0;
    }
    else {
        e = queue[front];
        queue[front] = 0;   //making value NULL
        
        if(front == rear) {
            front = -1;
            rear = -1;
        }       //single element in queue
        else {
            front = (front+1)%size;
        }
    }
    return e;
}


void display() {
    for(int i=front; i!=rear+1; (i++)%size) {       
        //(rear+1) coz it doesn't print the last element
        //F=2, R=1 so 2-3-4-0-1 order doesn't matter, traverese whole queue
        
        if(queue[i] != 0) {     //avoid print of NULL entries
            printf("%d ", queue[i]);    
        }
    }
}


