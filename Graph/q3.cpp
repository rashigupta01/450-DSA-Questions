vector<int>dfsOfGraph(int V, vector<int> adj[]){
    vector<int> dfs;
    vector<bool> visited(V);
    
    dfsUtil(adj, dfs, 0, visited);
}

void dfsUtil (vector<int> &adj[], vector<int> &dfs, int src, vector<bool> &visited) {
    visited[src] = true;
    dfs.push_back(src);
    for (auto ele : adj[src]) {
        if (!visited[ele]) dfsUtil(adj, dfs, src, visited);
    }
}