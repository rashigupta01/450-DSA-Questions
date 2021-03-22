// My code
bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    for (int i=0; i<V; i++) {
        if (!visited[i]) {
            if (util (adj, visited, i, -1)) return true;
        }
    }
    return false;
}
bool util (vector<int> adj[], vector<bool> &visited, int source, int prev) {
    
    visited[source] = true;
    for (auto ele : adj[source]) {
        if (visited[ele] && ele != prev) return true;
        if (!visited[ele]) {
            if (util (adj, visited, ele, source)) return true;
        }
    }
    return false;
}