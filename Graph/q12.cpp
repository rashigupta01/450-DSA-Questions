#include<bits/stdc++.h>
using namespace std;

class Graph {
    public:
        int vertices;
        vector<pair<int, int>> *adj;

        Graph (int vertices) {
            this->vertices = vertices;
            adj = new vector<pair<int, int>> [vertices];
        }

        void addEdge (int a, int b, int wt) {
            adj[a].push_back(make_pair(b, wt));
            adj[b].push_back(make_pair(a, wt));
        }
};

void shortestDistace(Graph g) {

	priority_queue < pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>> > pq;     // creating a min heap

	int source = 0;     // starting with 0
	vector<int> key(g.vertices, INT_MAX);       // vector to store minimum wieght/distance  
	vector<bool> visited (g.vertices, false);   // vector to check if a node is already in mst or not

	pq.push({0, source});
	key[source] = 0;

	while (!pq.empty()) {
		int cur_node = pq.top().second;
		pq.pop();

		visited[cur_node] = true;   // include current element into MST

		for (auto ele : g.adj[cur_node]) {
    
            if (!visited[ele.first] && key[ele.first] > ele.second + key[cur_node]) {

				key[ele.first] = ele.second + key[cur_node];
				pq.push({key[ele.first], ele.first});
			}
		}
	}
    for (int i = 0; i < g.vertices; ++i)
		outfile << i << " - " << key[i] << endl;
}

/* Driver code*/
int main() {

    int t;
    cin >> t;

	while(t--) {
	    
        int no_of_edges, no_of_vertices;      // number of edges in graph
        cin >> no_of_edges >> no_of_vertices;

        Graph g(no_of_vertices);
        for (int i=0; i<no_of_edges; i++) {

            int a, b, wt;
            cin >> a >> b >> wt;
            g.addEdge(a, b, wt);
        }

        shortestDistace(g);

        cout << endl;
	}

	return 0;
}
