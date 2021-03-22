void backtrack(vector<vector<int>>& m, int n, vector<vector<bool>> &visited, int i, int j, vector<string> &result, string path="") {
    
    visited[i][j] = true;
    
    if (i==j && i==n-1) {
        result.push_back(path);
        visited[i][j]=false;
        return;
    }
    
    int move[][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    char dir[] = {'D', 'L', 'R', 'U'};
    
    for (int k=0; k<4; k++) {
        int newi= i + move[k][0];
        int newj = j + move[k][1];
        if (newi<0 || newi>=n || newj<0 || newj>=n) {
            continue;
        }
        
        if (!visited[newi][newj] && m[newi][newj]==1) {
            backtrack(m, n, visited, newi, newj, result, path+dir[k]);
        }
    }
    visited[i][j] = false;
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    
    vector<string> result;
    if (m[0][0] == 0) return result;
    
    vector<vector<bool>> visited (m.size());
    for (int i=0; i<m.size(); i++) {
        visited[i] = vector<bool> (m[0].size());
    }
    backtrack(m, n, visited, 0, 0, result);    
    return result;
}