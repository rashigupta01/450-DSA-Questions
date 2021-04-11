// https://www.geeksforgeeks.org/find-longest-path-directed-acyclic-graph/

// Dijkstra won't work as we might need to revisit a node
// to avoid revisiting we would use topsort (as the graph is dag) and relax the node one by one

#include <bits/stdc++.h> 
using namespace std;

class Graph {
	public:
	int v;
	vector<pair<int, int>>* adj;

    void topsort_util (int src, vector<bool> &visited, vector<int>& topsort) {
        visited[src] = true;
        for (auto next : adj[src]) {
            if (!visited[next.first]) topsort_util(next.first, visited, topsort); 
        }
        topsort.push_back(src);
    }

	vector<int> topological_sort() {
        vector<bool> visited (v, false);
        vector<int> topsort;
        for (int i=0; i<v; i++) {
            if (!visited[i]) topsort_util(i, visited, topsort);
        }
        reverse(topsort.begin(), topsort.end());

        return topsort;
    }

    Graph(int v) {
        this->v = v;
        adj = new vector<pair<int, int>>[v];
    }
    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight}); // Add v to u's list
    }

	void longestPath(int s) {
        vector<int> dist(v, INT_MIN);
        dist[s] = 0;

        vector<int> top_order = topological_sort();
        		
        for (int i=0; i<v; i++) {
            int cur = top_order[i];
            if (dist[cur] == INT_MIN) continue;
            for (auto next : adj[cur]) {
                if (dist[cur] + next.second > dist[next.first]) {
                    dist[next.first] = dist[cur] + next.second;
                }
            }
        }
        for (int i = 0; i < v; i++)
            (dist[i] == INT_MIN) ? cout << "INF " : cout << dist[i] << " ";
    }
};

int main()
{
	// Create a graph given in the above diagram.
	// Here vertex numbers are 0, 1, 2, 3, 4, 5 with
	// following mappings:
	// 0=r, 1=s, 2=t, 3=x, 4=y, 5=z
	Graph g(6);
	g.addEdge(0, 1, 5);
	g.addEdge(0, 2, 3);
	g.addEdge(1, 3, 6);
	g.addEdge(1, 2, 2);
	g.addEdge(2, 4, 4);
	g.addEdge(2, 5, 2);
	g.addEdge(2, 3, 7);
	g.addEdge(3, 5, 1);
	g.addEdge(3, 4, -1);
	g.addEdge(4, 5, -2);

	int s = 1;
	cout << "Following are longest distances from "
			"source vertex "
		<< s << " \n";
	g.longestPath(s);

	return 0;
}