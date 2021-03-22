#include<bits/stdc++.h>
using namespace std;

// Creating a class Graph 
class Graph {

	public:
	    map <int, vector<int> > adj;
    
		void addEdge (int x, int y) {

			// Considering undirectional graph
            adj[x].push_back(y);
			adj[y].push_back(x);
		}
        
        void printGraph() {
            for(auto i : adj) {
                cout<<endl<<i.first<<" -> ";
                for(auto j : i.second) cout<<j<<",";
            }
        }
};


/* Driver code*/
int main() {

    Graph g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 0);
    g.addEdge(0, 2);
    g.addEdge(5, 3);
    g.addEdge(1, 4);
    g.printGraph();

	return 0;
}