// Basically we have to find the topological sorting of the graph created using adjacent words in the dictionary
class Graph {
    public:
        int v;
        vector<int> *adj;
    
        Graph (int _v) {
            v = _v;
            adj = new vector<int> [v];
        }
        void addEdge (int a, int b) {
            adj[a].push_back(b);
        }
        string get_top_sort () {
            string top_sort;
            vector<bool> visited (v);
            for (int i=0; i<v; i++) {
                if (!visited[i]) {
                    dfs_visit(i ,visited, top_sort);
                }
            }
            reverse (top_sort.begin(), top_sort.end());
            return top_sort;
        }
        void dfs_visit (int src, vector<bool>& visited, string& top_sort) {
            visited[src] = true;
            for (auto ele : adj[src]) {
                if (!visited[ele]) {
                    dfs_visit (ele, visited, top_sort);
                }
            }
            top_sort.push_back (src + 'a');
        }
};

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        Graph g(K);
        
        for (int i=1; i<N; i++) {
            int p1 = 0;
            while (p1<dict[i-1].size() && p1<dict[i].size()) {
                if (dict[i-1][p1] != dict[i][p1]) {
                    g.addEdge (dict[i-1][p1]-'a', dict[i][p1]-'a');
                    break;
                }
                p1++;
            }
        }
        
        string result = g.get_top_sort ();
        return result;
    }
};