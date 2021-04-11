class Solution{
    public:
    vector<string> result;
    vector<vector<int>> move {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    vector<char> dir {'D', 'L', 'R', 'U'};
        
    void backtrack(vector<vector<int>>& m, int n, int i = 0, int j = 0, string path="") {
        
        if (i==j && i==n-1) {
            result.push_back(path);
            return;
        }
        
        m[i][j] = 0;
        
        for (int k=0; k<4; k++) {
            int newi= i + move[k][0];
            int newj = j + move[k][1];
            if (newi<0 || newi>=n || newj<0 || newj>=n || !m[newi][newj]) {
                continue;
            }
            
            backtrack(m, n, newi, newj, path+dir[k]);
        }
        m[i][j] = 1;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        if (m[0][0] == 0) return result;
        
        backtrack(m, n);    
        return result;
    }
};