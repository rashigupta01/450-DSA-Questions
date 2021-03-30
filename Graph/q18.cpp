#include <bits/stdc++.h>
using namespace std;

class Edge{
	public:
	int source, destination , weight;
	
	Edge(int u, int v, int w){
		source = u;
		destination = v;
		weight = w;
	}
};

// user defined method for 'sort'
bool comparision (Edge a, Edge b) {
	return a.weight < b.weight;
}

int find_in_set (int a, vector<pair <int, int>>& subset) {
    if (subset[a].first == -1) return a;

    // doing PATH COMPRESSION
    subset[a].first = find_in_set (subset[a].first, subset);
    return subset[a].first;
}

bool isCycle (int a, int b, vector<pair<int, int>>& subset) {

	if (find_in_set(a, subset) == find_in_set(b, subset)) {
		return true;
	}
	return false;
}

void union_of_sets (int a, int b, vector<pair <int, int>>& subset){

    // UNION BY RANK (size) : Keeping the shorter set in b 
	if(subset[a].second < subset[b].second) {
        swap (a, b);
	}

    int a_rep = find_in_set(a, subset);
    int b_rep = find_in_set(b, subset);

    // if (a_rep == b_rep) return;

    subset[b_rep].first = a_rep;

    if (subset[a_rep].second == subset[b_rep].second) subset[a_rep].second++;
}

class Graph {
    public:
    int v;
    vector<pair<int, int> > *adj;

    Graph (int _v) {
        v = _v;
        adj = new vector<pair<int, int> > [_v];
    }
    void addEdge (int a, int b, int w) {
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    Graph krushkal_mst () {

        vector<Edge> edges;
        Graph mst (v);
        for (int i=0; i<v; i++) {
            for (auto next : adj[i]) {
                Edge tempEdge (i, next.first,  next.second);
                    edges.push_back (tempEdge);
            }
        }

        sort (edges.begin(), edges.end(), comparision);

        vector<pair<int, int>> subset(v, {-1, 0});
        for (int i=0; i<edges.size(); i++) {

            if (!isCycle(edges[i].source, edges[i].destination, subset)) {
                union_of_sets(edges[i].source, edges[i].destination, subset);
                mst.addEdge(edges[i].source, edges[i].destination, edges[i].weight);
            }
        }

        return mst;
    }
    void print_graph () {
        cout << "Neighbours of each vertex with weight:" <<endl;
        for (int i=0; i<v; i++) {
            cout << i << "-> ";
            for (auto next : adj[i]) {
                cout << "(" << next.first << ", " << next.second << ") ";
            }
            cout << endl;
        }
    }
};

int main () {

	int t;
    cin >> t;

	while(t--) {
	    
        int no_of_edges, no_of_vertices;      // number of edges and vertices in graph
        cin >> no_of_vertices >> no_of_edges;

        Graph g(no_of_vertices);
        for (int i=0; i<no_of_edges; i++) {

            int a, b, wt;
            cin >> a >> b >> wt;
            g.addEdge(a, b, wt);
        }
        Graph mst = g.krushkal_mst();

		mst.print_graph();
        cout << endl;
	}
	return 0;	
}