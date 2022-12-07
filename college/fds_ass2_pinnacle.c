/*
Department of Information Technologyhas a student's club named 'Pinnacle Club'. Students of the Second, third and final  year of the department can be granted membership on request. Similarly, one may cancel the membership of the club. 
The first node is reserved for the president of the club and the last  node  is  reserved  for the secretary  of the club.
Write  C  program  to  maintain  club member‟s information using a singly linked list. Store student PRN and Name. 
Write functions to	a)Add and delete the members as well as the president or even secretary. 
			b)Compute the total number of members of the club
			c)Display members of the club
			d)Display list in reverse order using recursion
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    char name [20];
    int PRN;
    struct node *prev;
    struct node *next;
};

struct node* insertP(struct node *head, int *flagP);
void insertS(struct node *head, int *flagS);
void insertM(struct node *head);
void display(struct node *head, int *flagP, int *flagS);
struct node* deleteP(struct node *head, int *flagP);
void deleteS(struct node *head, int *flagS);
void deleteM(struct node *head);
int count(struct node *head);
void dispReverse(struct node *temp, int flagP, int flagS, int *c, int count);

int main()
{
    struct node *head = NULL, *temp;

    int flagP=0;
    int flagS=0;

    int choice, y, c=0;

    do {
        printf("\n----Menu----\n");
        printf("1. Insert Pesident\n");
        printf("2. Insert Secratary\n");
        printf("3. Insert Member\n");
        printf("4. Delete President\n");
        printf("5. Delete Secratary\n");
        printf("6. Delete Member\n");
        printf("7. Number of Members\n");
        printf("8. Display Reverse Linked list\n");
        printf("9. Display\n\n");
        
        printf("Enter your choice: ");
        scanf("%d",&choice);
        printf("\n");
        int m=1;
        switch(choice) {
            case 1:
                head = insertP(head, &flagP);
                break;

            case 2:
                insertS(head, &flagS);
                break;
                
            case 3:
                insertM(head);
                break;
                
            case 4:
                head = deleteP(head, &flagP);
                break;
                
            case 5:
                deleteS(head, &flagS);
                break;
                
            case 6:
                deleteM(head);
                break;
                
            case 7:
                printf("No. of menmbers = %d\n", count(head));
                break;
                
            case 8:
                temp = head;
                while(temp->next!=NULL) {
                    temp=temp->next;
                }
                dispReverse(temp, flagP, flagS, &c, count(head));            
                break;
                
            case 9:
                display(head, &flagP, &flagS);
                break;
            
            default:
                printf("Invalid choice!\n");
        }
        printf("\nDo You Want To Continue(0/1): ");
        scanf("%d", &y);
    }while(y==1);
    

        
    
    return 0;
}



struct node* insertP(struct node *head, int *flagP) {
    *flagP = 1;
    
    struct node *new;
    
    new = (struct node*)malloc(sizeof(struct node));
    new->prev = NULL;       new->next = NULL;
    
    printf("Enter President Name and PRN No.: ");
    scanf(" %s%d", new->name, &new->PRN);
	
    if(head == NULL) {
    	head = new;
	}
	else {
		head->next = head;
		head->prev = NULL;
	}
	
    // printf("President: %s %d", head->name, head->PRN);
	return head;
}

void insertS(struct node *head, int *flagS) {
    *flagS = 1;
    struct node *new, *temp;
    new = (struct node*)malloc(sizeof(struct node));
    new->prev = NULL;   new->next = NULL;
    printf("\nEnter Secretary Name and PRN No.: ");
    scanf(" %s%d", new->name, &new->PRN);

    temp = head;
    while(temp->next != NULL) {		//temp = last_node
        temp = temp->next;
    }
    temp->next = new;
	new->prev = temp;    
}

void insertM(struct node *head) {
    struct node *new, *temp;
	new = (struct node*)malloc(sizeof(struct node));
    new->prev = NULL;   new->next = NULL;
    
    int n;
    printf("\nEnter no. of members: ");
    scanf("%d", &n);
    
    temp = head;
    for(int i=0; i<n; i++) {
        new = (struct node*)malloc(sizeof(struct node));
        printf("Enter member-%d Name and PRN No.: ", i+1);
        scanf(" %s%d", new->name, &new->PRN);
        new->next = temp->next;     //new->next = secretary so that secretary is not lost
        new->prev = temp;
        temp->next = new;       //head->next = new
        temp = new->next;       //temp=new->next = secretary
        temp->prev = new;	    //secretary->prev = new
        temp = new;        
    }
}

struct node* deleteP(struct node *head, int *flagP) {
    *flagP = 0;
    struct node *temp;
    temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);

    return head;
}

void deleteS(struct node *head, int *flagS) {
    *flagS = 0;
    struct node *temp;
    temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    printf("beforeSec Name=%s PRN=%d\n", temp->prev->next->name, temp->prev->next->PRN);
    temp->prev->next = NULL;    //(temp->prev)->next = beforeSec->next
    free(temp);
}

void deleteM (struct node *head) {
    int prn;
    printf("Enter PRN of member to delete: ");
    scanf("%d", &prn);

    struct node *temp = head;
    while(temp->PRN != prn) {
        temp = temp->next;
    }
    if(temp->next != NULL) {            //only when Secretary is present
        temp->next->prev = temp->prev;      
    }
    temp->prev->next = temp->next;      //when No Secretary
    free(temp);
} 

void display(struct node *head, int *flagP, int *flagS) {
	struct node *temp;
    temp=head;
	    
    if(*flagP == 1) {
        printf("\nPrsdnt-\n");       //temp == head
        printf("Name: %s\tPRN: %d\n", temp->name, temp->PRN);

        temp = temp->next;
		// getchar(); getchar();
    }
    
    if(*flagS == 0) {
        while(temp != NULL) {     //(temp != NULL) then last node will Also get printed
            printf("Member-\n");
            printf("Name: %s\tPRN: %d\n", temp->name, temp->PRN);
            printf("\n"); 
            temp = temp->next;       
        }
    }
    else {
        // if(*flagS == 1)
        while(temp->next != NULL) {     //(temp->next != NULL) then last node will Not get printed
            printf("Member-\n");
            printf("Name: %s\tPRN: %d\n", temp->name, temp->PRN);
            printf("\n");
            temp = temp->next;      
        }        
        printf("Secretary-\n");       //now temp->next == NULL,     so temp = addrs_of_last_node
        printf("Name: %s\tPRN: %d\n", temp->name, temp->PRN);
        printf("\n");
    }

    // else 
    //     printf("Error!\n");
}

int count(struct node *head) {
    struct node* temp;
    temp = head;
    int c=1;
    while(temp->next != NULL) {
        c++;
        temp = temp->next;
    }
    return c;
}

void dispReverse(struct node *temp, int flagP, int flagS, int *c, int count) {

    if(temp != NULL) {
        if(*c > count) {
            *c=0;
        }

        if(flagS == 1 && *c == 0 ) {
            printf("\nSecretary-\n");       
            printf("%s\t%d\n", temp->name, temp->PRN);
            *c++;
        }
        else if(flagP == 1 && *c == count+1) {
            printf("\nPresident-\n");
            printf("%s\t%d\n", temp->name, temp->PRN);
        }
        else {
            printf("\nMember-\n"); 
            printf("%s\t%d\n", temp->name, temp->PRN);
            *c++;
        }

        temp = temp->prev;
        dispReverse(temp, flagP, flagS, c, count);
    }
}