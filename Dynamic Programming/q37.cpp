// consider the current element or ignore it
// space complexity (O(N*W))
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        int dp[N+1][W+1];
        memset (dp, 0, sizeof dp);
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=W; j++) {
                if (wt[i-1] <= j) {
                    dp[i][j] = max (dp[i-1][j], dp[i][j-wt[i-1]] + val[i-1]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[N][W];
    }
};

// BETTER APPROACH : space complexity (O(W))
// maintain a 1d dp array of size W
// dp[i] denotes maximum value with limit 'j'
// for each i set dp[i]  = max (dp[i], dp[i-wt[j]]+val[j]) where j lies from 0 to N

// Note this idea can't be applied to other knapsack problems because when an item is included then it can't be repeated.
int knapSack(int n, int W, int val[], int wt[]) {
    int dp[W+1];
    memset(dp, 0, sizeof dp);
 
    for (int i=0; i<=W; i++)
      for (int j=0; j<n; j++)
         if (wt[j] <= i)
            dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);
 
    return dp[W];
}