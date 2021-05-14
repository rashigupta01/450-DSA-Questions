// Approach 1 : Backtracking (exponential)
#include <bits/stdc++.h>
using namespace std;
#define R 12
#define C 10

vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool safe (int mat[R][C], int i, int j) {
    for (int m=0; m<dir.size(); m++) {
        int newi = i+dir[m][0];
        int newj = j+dir[m][1];
        if (newi<0 || newi>=R || newj<0 || newj>=C) continue;
        if (mat[newi][newj] == 0) return false;
    }
    return true;
}

int util (int mat[R][C], int i, int j, int moves, bool visited[R][C]) {
    
    if (i<0 || i>=R || j<0 || j>=C || !safe(mat, i, j) || visited[i][j]) {
        return -1;
    }
    if (j==C-1) {
        return moves;
    }
    visited[i][j] = true;
    int result = INT_MAX;
    for (int m = 0; m<dir.size(); m++) {
        int next_possible = util (mat, i+dir[m][0], j+dir[m][1], moves+1, visited);
        if (next_possible!=-1)
            result = min (result, next_possible);
    }
    visited[i][j] = false;
    return result==INT_MAX ? -1 : result;
}

int findShortestPath(int mat[R][C]) {
    bool visited [R][C];
    memset(visited, false, sizeof(visited));
    int steps = INT_MAX;
    for (int i=0; i<R; i++) {

        int cur_steps = util (mat, i, 0, 0, visited);
        if (cur_steps!=-1)
            steps = min (steps, cur_steps);
    }
    return steps == INT_MAX ? -1 : steps;
}

// Driver code
int main()
{
	// input matrix with landmines shown with number 0
	int mat[R][C] =
	{
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
	};

	// find shortest path
	cout << findShortestPath(mat);

	return 0;
}

// Approach 2 : BFS (polynomial)
// push in the queue along with the moves