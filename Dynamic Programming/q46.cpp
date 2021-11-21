// My code :-
bool findWinner(int x, int y, int n)
{
    // row 0 represent B
    // row 1 represent A
    bool dp[2][n+1];
    dp[0][0] = true;
    dp[1][0] = false;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<2; j++) {
            if (i>=1) {
                dp[j][i] = dp[(j+1)%2][i-1];
            } 
            if (i>=x) {
                bool wins = dp[(j+1)%2][i-x];
                if (wins && j) dp[j][i] = true;
                if (!wins && !j) dp[j][i] = false;
            }
            if (i>=y) {
                bool wins = dp[(j+1)%2][i-x];
                if (wins && j) dp[j][i] = true;
                if (!wins && !j) dp[j][i] = false;
            }
        }
    }
    return dp[1][n];
}
 
// NOTE:::
// It is needless to create a matrix if two rows. Reason: if at any coin A wins then it is obvious that b will lose
// that means the matrix i have created will be negation of each other
// Following is the code on gfg:
bool findWinner(int x, int y, int n)
{
    // To store results
    int dp[n + 1];
 
    // Initial values
    dp[0] = false;
    dp[1] = true;
 
    // Computing other values.
    for (int i = 2; i <= n; i++) {
 
        // If A losses any of i-1 or i-x
        // or i-y game then he will
        // definitely win game i
        if (i - 1 >= 0 and !dp[i - 1])
            dp[i] = true;
        else if (i - x >= 0 and !dp[i - x])
            dp[i] = true;
        else if (i - y >= 0 and !dp[i - y])
            dp[i] = true;
 
        // Else A loses game.
        else
            dp[i] = false;
    }
 
    // If dp[n] is true then A will
    // game otherwise  he losses
    return dp[n];
}