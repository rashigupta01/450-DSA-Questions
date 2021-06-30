// my bfs approach using queue
// similar on editorial
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        
        vector<vector<int>> dir {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int n = grid.size();
        int m = grid[0].size();
        int total = 0, rotten=0;
        queue<pair<int, int>> rqueue;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j]) total ++;
                if (grid[i][j] == 2) {
                    rotten++;
                    rqueue.push({i, j});
                }
            }
        }
        int counter = 0;
        while (!rqueue.empty()) {
            counter++;
            int cur = rqueue.size();
            for (int i=0; i<cur; i++) {
                auto orange = rqueue.front();
                rqueue.pop();
                for (int j=0; j<dir.size(); j++) {
                    int posi = orange.first+dir[j][0];
                    int posj = orange.second+dir[j][1];
                    if (posi<0 || posi>=n || posj<0 || posj>=m) continue;
                    
                    if (grid[posi][posj]==1) {
                        grid[posi][posj] = 2;
                        rotten++;
                        rqueue.push({posi, posj});
                    }
                }
            }
        }
        
        return rotten==total ? (total ? counter-1 : counter) : -1;
    }
};