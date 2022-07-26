// My DP approach using 3D matrix
long long dp[1001][1001][2];
long long util (int arr[], int i, int j, bool turn) {
    if (i>j) return 0;
    if (i==j) return turn ? arr[i] : 0;
    if (i==j-1) return turn ? max(arr[i], arr[j]) : min(arr[i], arr[j]);
    
    if (dp[i][j][turn] != -1) return dp[i][j][turn];
    if (turn) {
        return dp[i][j][turn] = max (arr[i] + util(arr, i+1,j, 0), arr[j] + util (arr, i, j-1, 0));
    } else {
        return dp[i][j][turn] = min (util (arr, i+1, j, 1), util (arr, i, j-1, 1));
    }
    
}
long long maximumAmount(int arr[], int n) 
{
    memset (dp, -1, sizeof(dp));
    return util (arr, 0, n-1, 1);
}

// reducing to 2D matrix
// F(i, j) = Max(Vi + min(F(i+2, j), F(i+1, j-1) ), 
//               Vj + min(F(i+1, j-1), F(i, j-2) ))