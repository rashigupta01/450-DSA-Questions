
vector<int>bfsOfGraph(int V, vector<int> adj[]){
	queue<int> q;
	vector<int> res;
	vector<bool> visited(V, false);
	q.push(0);
	visited[0] = true;
	while (!q.empty()) {
		int temp = q.front();
		res.push_back(temp);
		q.pop();
		for (auto ele : adj[temp]) {
			if (!visited[ele]) {
				q.push(ele);
				visited[ele] = true;
			}
		}
	}
	return res;
}