#include <bits/stdc++.h>
using namespace std;

void dfsUtil(int node, vector<int> adj[], vector<int>& visited) {
    visited[node] = 1;
    cout << node << " ";
    for(int it : adj[node])
        if(!visited[it])
            dfsUtil(it, adj, visited);
}

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<int> adj[v];
    cout << "Enter edges (u v):\n";
    for(int i = 0; i < e; i++) {
        int u, w;
        cin >> u >> w;
        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    int start;
    cout << "Enter start node: ";
    cin >> start;

    cout << "\nDFS Traversal: ";
    vector<int> visited(v, 0);
    dfsUtil(start, adj, visited);

    cout << endl;
    return 0;
}
