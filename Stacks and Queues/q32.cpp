// my bfs code
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> dir {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	    vector<vector<int>> matrix (n, vector<int> (m));
        queue<pair<int, int>> q;
	    
	    for (int i=0; i<n; i++) {
	        for (int j=0; j<m; j++) {
	            matrix[i][j] = INT_MAX;
	            if (grid[i][j]) {
	                q.push({i, j});
	                matrix[i][j] = 0;
	            }
	        }
	    }
	    
	    int distance = 0;
	    while (!q.empty()) {
	        int size = q.size();
	        distance++;
	        
	        for (int i=0; i<size; i++) {
	            int x = q.front().first;
	            int y = q.front().second;
	            q.pop();
	            
	            for (int j=0; j<dir.size(); j++) {
                    int newx = x+dir[j][0];
                    int newy = y+dir[j][1];
                    if (newx<0 || newx>=n || newy<0 || newy>=m) continue;
                    
                    if (matrix[newx][newy] > distance) {
                        matrix[newx][newy] = distance;
                        q.push({newx, newy});
                    }
                }
	        }
	    }
        return matrix;
	}
};