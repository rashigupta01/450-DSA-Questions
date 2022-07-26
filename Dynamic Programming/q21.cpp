// O(n^2) DP approach
int longestSubsequence(int N, int A[])
{
    vector<int> dp (N, 1);
    int res = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<i; j++) {
            if (abs(A[i]-A[j]) == 1) {
                dp[i] = max (dp[i], dp[j] + 1);
            }
        }
        res = max (res, dp[i]);
    }
    return res;
}

// O(n) map approach
/*
    instead of dp vector have dp map
    for each element look for ele-1 and ele+1 value in map
    update accordingly
*/