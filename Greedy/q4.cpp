class Graph {
    public:
    int v;
    vector<pair<int, int>> *adj;
    Graph (int v) {
        this->v = v;
        adj = new vector<pair<int, int>> [v];
    }
    void addEdge (int a, int b, int wt) {
        adj[a].push_back({b, wt});
    }
};

class Solution
{
    public:
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        Graph g(n);
        for (int i=0; i<p; i++) {
            g.addEdge (a[i]-1, b[i]-1, d[i]);
        }
        vector<int> in(n, 0);
        for (int i=0; i<n; i++) {
            for (auto next : g.adj[i]) {
                in[next.first]++;
            }
        }
        vector<vector<int>> result;
        for (int i=0; i<n; i++) {
            if (in[i]==0 && !g.adj[i].empty()) {
                int start = i, end = i, dia = INT_MAX;
                while (!g.adj[end].empty()) {
                    dia = min (dia, g.adj[end][g.adj[end].size()-1].second);
                    end = g.adj[end][g.adj[end].size()-1].first;                
                }
                result.push_back ({start+1, end+1, dia});
            }
        }
        return result;
    }
};