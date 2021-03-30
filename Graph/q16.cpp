
// globlly declaring declaring direction vector
const vector<vector<int>> dir {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void dfs_visit (vector<vector<char>>& grid, int r, int c) {
    
    if (r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]!='1') return;

    grid[r][c] = '0';
        
    for (int i=0; i<dir.size(); i++) 
        dfs_visit (grid, r + dir[i][0], c + dir[i][1]);
}

int num_of_islands (vector<vector<char>>& grid) {
    int island_count = 0;
    
    for (int i=0; i<grid.size(); i++) {
        for (int j=0; j<grid[0].size(); j++) {
            if (grid[i][j] == '1') {
                island_count++;
                dfs_visit(grid, i, j);
            }
        }
    }
    return island_count;
}
