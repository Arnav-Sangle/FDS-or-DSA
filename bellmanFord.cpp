#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// void bellmanFord(vector<vector<int>> graph, int distance[]) {
//     for (int i : graph) {
        
//     }
// }

typedef struct Edge {
    int u;  //source node
    int v; //destination node
    int w; //weight of edge, cost of dist btwn u & v
} Edge;

typedef struct Graph {
    int V;  //no. of vertexes
    int E;  //no. of edges
    struct Edge *e;  //
} Graph;


int main() {
    Graph *g;   //struct Graph *g;
    g = new Graph;
    cout << g;
       
    // vector<vector<int>> graph = { {INF, 4, 2, INF, INF},
    //                         {INF, INF, 3, 2, 4},
    //                         {INF, 1, 2, INF, 4, 5},
    //                         {INF, INF, INF, INF, INF},
    //                         {INF, INF, INF, INF, -5}
    //                     }
    //  vector<int> distance = {INF, INF, INF, INF, INF};
}


