#include <bits/stdc++.h>
using namespace std;

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

    vector<int> visited(v, 0);
    queue<int> q;
    
    visited[start] = 1;
    q.push(start);

    cout << "\nBFS Traversal: ";
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        
        for(int it : adj[node]) {
            if(!visited[it]) {
                visited[it] = 1;
                q.push(it);
            }
        }
    }

    cout << endl;
    return 0;
}
