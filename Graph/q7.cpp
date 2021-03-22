// int result;
    void util (int x, int y, vector<int>& target, int N,  int stepcount, vector<vector<int>> &visited) {
        
        if (x == target[0] && y == target[1]) {
            // result = min (result, stepcount);
            return;
        }
        
        int dir[][2] = {{2, -1}, {2, 1}, {1, 2}, {1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {-1, -2}};
	    
	    for (int i=0; i<8; i++) {
	        int newx = x + dir[i][0];
	        int newy = y + dir[i][1];
	        
	        if (newx<=0 || newx>N || newy<=0 || newy>N) {
                continue;
            }
            
            if (stepcount + 1 < visited[newx-1][newy-1]) {
                visited[newx-1][newy-1] = stepcount+1;
                util(newx, newy, target, N, stepcount+1, visited);
            }
	    }
    }
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    
	   // result = INT_MAX;
	    vector<vector<int>> visited(N);
	    for (int i=0; i<N; i++) {
	        visited[i] = vector<int> (N, INT_MAX);
	    }
	    util (KnightPos[0], KnightPos[1], TargetPos, N, 0, visited);
	    
	   // return result;
	   return visited[TargetPos[0]][TargetPos[1]];
	}