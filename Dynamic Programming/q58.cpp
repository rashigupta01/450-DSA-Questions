int maxProfit(int K, int N, int A[]) {    
    vector<vector<int>> dp(N, vector<int> (K+1, 0));
    int res = 0;
    for (int i=1; i<N; i++) {
        for (int j=1; j<=K; j++) {
            dp[i][j] = dp[i-1][j];
            int temp = 0;
            for (int k=0; k<i; k++) {
                if (A[k] < A[i]) {
                    temp = A[i] - A[k];
                    if (k>0) temp += dp[k-1][j-1];
                }
                dp[i][j] = max (dp[i][j], temp);
            }
            res = max (res, dp[i][j]);
        }
    }
    return res;
}

// refer optimization: https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-k-times/
/*
max(price[i] – price[j] + profit[t-1][j]) 
for all j in range [0, i-1]
can be rewritten as, 
= price[i] + max(profit[t-1][j] – price[j]) 
for all j in range [0, i-1] 
= price[i] + max(prevDiff, profit[t-1][i-1] – price[i-1]) 
*/