#include <bits/stdc++.h>
using namespace std;

#define n 5
int a[n][n], visited[n];
int Stack[20];
int top=-1; 

void DFS(int v);

int main() {
    int v;
    cout << "Enter the matrix: ";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }
    
    for(int i=0; i<n; i++) {
        visited[i] = 0;
    }
    
    cout << "Enter Source vertex: ";
    cin >> v;
    
    cout << "DFS Traversal-" << endl;
    DFS(v);
    cout << endl;
    
    return 0;
}

void DFS(int v) {
    visited[v] = 1;
    cout << v << " ";
    Stack[++top] = v;
    
    for(int i=0; i<n; i++) {
        if(a[v][i]==1 && !visited[i]) {
            DFS(i);
        }
    }
    
    while(top!=-1) {
        int e = Stack[top];
        int f=0;
        for(int i=0; i<n; i++) {
            if(a[e][i]==1 && !visited[i]) {
                DFS(i);
                f=1;
            }
        }
        
        if(f==0) {
            top--;
        }
    }
    
}

void BFS(int s) {
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
        
        cout<<v<<"\n";
        // for(int i=0; i<n; i++) {
        //     cout<<Queue[i]<<" ";
        // }
        cout<<endl;
        front++;

    }
    
}
