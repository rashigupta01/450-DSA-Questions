#include <bits/stdc++.h>
using namespace std;

// used BFS approach to find the shortest path to the end in a snake and ladder game
int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    vector<bool> visited (n*n+1);
    int level = 0;        
    
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur_level = q.size();
        
        for (int i=0; i<cur_level; i++) {
            int ele = q.front();
            q.pop();
            visited[ele] = true;
            if (ele == n*n) return level;
        
            int maxfar = 0;
            for (int j=1; j<=6; j++) {
                int next = ele+j;
                int nextrow = n - 1 - (next - 1)/n;
                int nextcol;
                if ((n - 1 - nextrow) & 1) {
                    nextcol = n - 1 - (next - 1) % n;
                } else {
                    nextcol = (next - 1) % n;
                }
                
                if (board[nextrow][nextcol] != -1) next = board[nextrow][nextcol];
                
                if (next == n*n) {
                    return level+1;
                }
                
                if (visited[next]) continue;
                
                if (board[nextrow][nextcol] != -1)
                    q.push(next);
                else 
                    maxfar = next;
            }
            if (maxfar)
                q.push(maxfar);
        }
        level++;
    }
    return -1;
}