#include <bits/stdc++.h>
#define n 6

int A[n][n];
int visited[n];

void DFS(int v)
{
    visited[v] = 1;
    for(int i=0;i<n;i++)
    {
        if(A[v][i] == 1 && !visited[i])
        {
            printf("The edge is [%d - %d]\n", v, i);
            DFS(i);
        }
    }
}

void main()
{
    int v;
    printf("Enter the matrix: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d", &A[i][j]);
            
        }
        printf("\n");
    }
    for(int i=0;i<n;i++)
    {
        visited[i] = 0;
    }
    printf("Enter the vertex: ");
    scanf("%d", &v);
    DFS(v);
}
