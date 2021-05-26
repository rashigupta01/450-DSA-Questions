// stack can also be used
vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> res;
    vector<bool> visited (V, false);
    
    for (int i=0; i<V; i++) {
        if (!visited[i])
            util (adj, i, visited, res);
    }
    reverse (res.begin(), res.end());
    return res;
}

void util(vector<int> adj[], int s, vector<bool>& visited, vector<int>& res) {
    
    visited[s] = true;
    for (auto ele : adj[s]) {
        if (!visited[ele])
            util(adj, ele, visited, res);
    }
    res.push_back(s);
}

// iterative method : Kahn's algorithm