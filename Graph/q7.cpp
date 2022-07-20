// NOT EFFICIENT : DFS approach, BFS would be a better choice

int dir[][2] = {{2, -1}, {2, 1}, {1, 2}, {1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {-1, -2}};

void util (int x, int y, vector<int>& target, int N,  int stepcount, vector<vector<int>> &visited) {
	
	if (x == target[0] && y == target[1]) {
		return;
	}
	
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
	
	vector<vector<int>> visited(N);
	for (int i=0; i<N; i++) {
		visited[i] = vector<int> (N, INT_MAX);
	}
	util (KnightPos[0], KnightPos[1], TargetPos, N, 0, visited);
	
	// return result;
	return visited[TargetPos[0]][TargetPos[1]];
}

// BFS approach
Class Solution 
{
    public:
    
    int dir[8][2] = {{2, -1}, {2, 1}, {1, 2}, {1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {-1, -2}};

    int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
    	
    	vector<vector<bool>> visited(N, vector<bool> (N, false));
    	queue<pair<int, int>> q;
    	int level = 0;

	    q.push({KnightPos[0], KnightPos[1]});
    	visited[KnightPos[0]-1][KnightPos[1]-1] = true;
    	
    	while (!q.empty()) {
    	    int count = q.size();
    	    
	    	for (int i=0; i<count; i++) {
    	    	auto temp = q.front();
    		    if (temp.first==TargetPos[0] && temp.second==TargetPos[1]) return level;
    		    
            	q.pop();
    		    for (int j=0; j<8; j++) {
    			    int newx = temp.first + dir[j][0];
    		        int newy = temp.second + dir[j][1];
    		        
    		
            		if (newx<=0 || newx>N || newy<=0 || newy>N || visited[newx-1][newy-1]) {
    	        		continue;
    		        }
    		
    			    q.push({newx, newy});
    			    visited[newx-1][newy-1] = true;
    		    }
    		}
    		level++;
    	}
    	return -1;
	}
};