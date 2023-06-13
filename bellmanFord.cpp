#include<bits/stdc++.h>
using namespace std;

#define INF 999
#define n 5

int bellmanFord(int s, int graph[][n], int distance[]);
void relax(int i, int graph[][n], int distance[]);


int main() {
    int graph[n][n] = { {INF, 5, -1, INF, INF},
                        {INF, INF, INF, -3, INF},
                        {INF, -2, INF, 6, 3},
                        {INF, INF, INF, INF, 2},
                        {INF, INF, INF, INF, INF}
    };
    
    //initializing all distance as INFINITY
    int distance[n];    
    for(int i=0; i<n; i++) {
        distance[i]=INF;
    }
    
    cout<<"\n*******BELLMAN FORD ALGORITHM*******\n";
    
    int s;
    cout<<"Enter Source node: ";
    cin>>s;
    distance[s]=0;
    
    cout<<"Distance vector Before: "<<endl;
    for(int i=0; i<n; i++) {
        if(distance[i]==INF) {
            cout<<"INF ";
        }
        else {
            cout<<distance[i]<<" ";
        }
    }
    cout<<endl<<endl;


    if(bellmanFord(s, graph, distance) == 1){
        cout<<"Distance vector After: "<<endl;
        for(int i=0; i<n; i++) {
            if(distance[i]==INF) {
                cout<<"INF ";
            }
            else {
                cout<<distance[i]<<" ";
            }
        }
        cout<<endl<<endl;
    }
    

} 




int bellmanFord(int s, int graph[][n], int distance[]) {

    for(int k=0; k<n-1; k++) {
        for(int i=0; i<n-1; i++) {
            relax(i, graph, distance);
            // for(int i=0; i<n; i++) {
            //     cout<<distance[i]<<" ";
            // }
            // cout<<endl;
        }
    }

    //copying distance vector of 'n-1'th iteration
    int tempDist[n];                
    for(int i=0; i<n; i++) {
        tempDist[i]=distance[i];
    }
    
    //after 'n'th iteration, if distance vector is not the same, then -ve cycle exists
    for(int i=0; i<n-1; i++) {
        relax(i, graph, distance);
    }
    
    for(int i=0; i<n; i++) {
        if(distance[i]!=tempDist[i]) {
            cout<<"Negative Cycle Exists"<<endl;
            cout<<"Thus, no Solution"<<endl;
            return -1;
        }
    }
    
    cout<<"Negative Cycle does Not exist"<<endl;
    return 1;
}



void relax(int u, int graph[][n], int distance[]) {
    int v;
    for(int i=0; i<n; i++) {
        v=i;
        
        if(graph[u][v]!=INF && distance[v]>distance[u]+graph[u][v]) {
            distance[v] = distance[u]+graph[u][v];
        }
    }
}



