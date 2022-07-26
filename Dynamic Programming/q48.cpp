// Exponential approach: got tle
// couldn't memoize it
int res = 0;
int util (int K, int N, int A[], int pos, int boughtAt, int cur) {
    if (pos == N || K==0) {
        return cur;
    }
    if (boughtAt!=-1) {
        return max (util (K, N, A, pos+1, boughtAt, cur), util (K-1, N, A, pos+1, -1, cur+A[pos]-boughtAt));
    } else {
        return max (util (K, N, A, pos+1, A[pos], cur), util (K, N, A, pos+1, -1, cur));
    }
}
int maxProfit(int K, int N, int A[]) {
    
    return util (K, N, A, 0, -1, 0);
}


// My DP approach: O(N*K*N)
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

// optimization: O(N*K)
// https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-k-times/