// Tabulation
int maxGold(int n, int m, vector<vector<int>> M)
{
    int dp[n+1][m+1];
    for (int j=0; j<=m; j++) {
        for (int i=0; i<=n; i++) {
            if (i==0 || j==0) {
                dp[i][j] = 0;
                continue;
            }
            int to_add =  max (dp[i][j-1], dp[i-1][j-1]);
            if (i!=n) to_add = max (to_add, dp[i+1][j-1]);
            dp[i][j] = M[i-1][j-1] + to_add;
        }
    }
    int result = INT_MIN;
    for (int i=0; i<=n; i++) result = max (result, dp[i][m]);
    return result;
}