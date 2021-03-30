// Approach 1 : keep a boolean vector to know the path. Now if a node points to any node in the current path there is a back edge
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

// Approach 2 : https://www.geeksforgeeks.org/detect-cycle-direct-graph-using-colors/
// White : not visited
// Grey : visited and being processed
// Black : visited and processed
// If a node points to grey node that means there is a back edge