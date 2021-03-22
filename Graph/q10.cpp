class Graph {
    public:
        int v;
        vector<int> *adj;
    
        Graph (int _v) {
            v = _v;
            adj = new vector<int> [_v];
        }
        void addEdge (int a, int b) {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int dfs () {
            int count = 0;
            vector<bool> visited(v, false);
            for (int i=0; i<v; i++) {
                if (!visited[i]) {
                    count++;
                    dfsUtil (i, visited);
                }
            }
            return count;
        }
        void dfsUtil (int source, vector<bool> &visited) {
            visited[source] = true;
            for (auto ele : adj[source]) {
                if (!visited[ele]) {
                    dfsUtil(ele, visited);
                }
            }
        }
};

class Solution {
public:
    
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) return -1;
    
        Graph g (n);
        for (int i=0; i<connections.size(); i++) {
            g.addEdge(connections[i][0], connections[i][1]);
        }
        return g.dfs() - 1;
    }
};
