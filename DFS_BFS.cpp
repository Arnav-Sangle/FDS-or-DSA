#include<bits/stdc++.h>
using namespace std;

#define n 5

// 0 1 1 1 0
// 1 0 1 0 0
// 1 1 0 0 1
// 1 0 0 0 0
// 0 0 1 0 0

int graph[n][n];
int visited[n];

int Stack[20];
int top=0;

int Queue[20];
int front=0;
int rear=-1;

void DFS(int v);
void BFS(int v);

int main() {
    
    cout<<"Enter the "<<n<<"x"<<n<<" matrix: "<<endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>graph[i][j];
        }
    }
    
    for(int i=0; i<n; i++) {
        visited[i] = 0;
    }
    
    int v;
    cout<<"Enter the Source vertex: ";
    cin>>v;
    
    cout<<"DFS Traversal: "<<endl;
    DFS(v);
    cout<<endl;
    
    
    for(int i=0; i<n; i++) {
        visited[i] = 0;
    }
    
    cout<<"Enter the Source vertex: ";
    cin>>v;
    
    cout<<"BFS Traversal: "<<endl;
    BFS(v);
    cout<<endl;
    
    return 0;
}



//if you reffering programiz, then their order is different 
//  coz they input in stack as 3,2,1 so 1 is their stack top
void DFS(int s) {   //LIFO, print during pop    
    visited[s] = 1;
    cout<<s<<" ";
    
    for(int i=0; i<n; i++) {
        if(graph[s][i]==1 && !visited[i]) {
            Stack[++top]=i;
            visited[i] = 1;
        }
    }
    
    while(top>0) {
        
        int v = Stack[top];
        cout<<v<<" ";
        top--;
        
        for(int i=0; i<n; i++) {
            if(graph[v][i]==1 && !visited[i]) {
                Stack[++top]=i;
                visited[i] = 1;
            }
        }
        
    }
    
}



void BFS(int s) {   //FIFO, print during pop 
    visited[s]=1;
    Queue[++rear]=s;
    
    while(front<=rear){
        int v = Queue[front];
        
        for(int i=0; i<n; i++) {
            if(graph[v][i]==1 && !visited[i]) {
                Queue[++rear]=i;
                visited[i]=1;
            }
        }
        
        cout<<v<<" ";
        front++;

    }
    
}

