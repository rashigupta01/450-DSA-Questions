// DFS approach
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
        }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g (numCourses);
        for (int i=0; i<prerequisites.size(); i++) {
            g.addEdge (prerequisites[i][1], prerequisites[i][0]);
        }
        
        vector<bool> visited(numCourses, false);
        for (int i=0; i<numCourses; i++) {
            if (!visited[i]) {
                vector<bool> path(numCourses, false);
                if (util (g.adj, visited, i, path)) return false;
            }
        }
        return true;    
    }
 
    bool util (vector<int> adj[], vector<bool> &visited, int source, vector<bool> &path) {

        visited[source] = path[source] = true;
        for (auto ele : adj[source]) {
            
            if (path[ele]) return true;
            if (!visited[ele] && util (adj, visited, ele, path)) return true;
        }
        path[source] = false;
        return false;
    }
};

// BFS approach : check if topological ordering is possible or not