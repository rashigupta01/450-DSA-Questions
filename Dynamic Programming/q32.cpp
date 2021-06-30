// My approach same as on gfg
int longestCommonSubstr (string S1, string S2, int n, int m) {

    int dp[n+1][m+1];
    memset(dp, 0, sizeof dp);
    int ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (S1[i-1]==S2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                ans = max (ans, dp[i][j]);
            }
        }
    }
    return ans;
}

// space can be optimized by considering table of two rows