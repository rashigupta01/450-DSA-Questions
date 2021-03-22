bool isCyclic(int V, vector<int> adj[]) {
	vector<bool> visited(V, false);
	for (int i=0; i<V; i++) {
		if (!visited[i]) {
			vector<bool> path(V, false);
			if (util (adj, visited, i, path)) return true;
		}
	}
	return false;
}
bool util (vector<int> adj[], vector<bool> &visited, int source, vector<bool> &path) {
	
	visited[source] = path[source] = true;
	for (auto ele : adj[source]) {
		if (path[ele]) return true;
		if (!visited[ele]) {
			if (util (adj, visited, ele, path)) { path[source] = false; return true;}
		}
	}
	path[source] = false;
	return false;
}
