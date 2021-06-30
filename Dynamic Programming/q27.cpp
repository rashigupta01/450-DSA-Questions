
// Approach: DP solution, for each element add the max value of the positions from where it can come to the current position
class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        for (int i=1; i<Matrix.size(); i++) {
            for (int j=0; j<Matrix[0].size(); j++) {
                int prev = Matrix[i-1][j];
                if (j>0) prev = max (prev, Matrix[i-1][j-1]);
                if (j<Matrix[0].size()-1) prev = max (prev, Matrix[i-1][j+1]);
                
                Matrix[i][j] += prev;
            }
        }
        
        int res = Matrix[Matrix.size()-1][0];
        for (int i=1; i<Matrix[0].size(); i++) {
            res = max (res, Matrix[Matrix.size()-1][i]);
        }
        return res;
    }
};