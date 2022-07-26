// ! My wrong approach
// Take lcs of first two then lcs with third, ie, return lcs(lcs(a, b), c)
// WHY WRONG? 
// LCS of the first 2 strings may not have anything common with the 3rd string. 
// May be any other common subsequence between the first 2 strings, not necessarily the longest one,
// may lead to the LCS of the 3 strings.


// ? correct approach
// create a 3d matrix and find lcs of 3 strings simultaneously similarly as we find lcs of 2 strings
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    int dp[n1+1][n2+1][n3+1];
    memset(dp, 0, sizeof(dp));
    for (int i=1; i<=n1; i++) {
        for (int j=1; j<=n2; j++) {
            for (int k=1; k<=n3; k++) {
                if (A[i-1] == B[j-1] && A[i-1] == C[k-1]) {
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                } else {
                    dp[i][j][k] = max (dp[i-1][j][k], max (dp[i][j-1][k], dp[i][j][k-1]));
                }
            }
        }
    }
    return dp[n1][n2][n3];
}