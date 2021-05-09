// Memoization : Reccursion
class Solution
{
  public:
    vector<vector<long long int>> v;
    
    long long int count( int S[], int m, int n) {
        v = vector<vector<long long int>> (n+1, vector<long long int> (m+1, -1));
        return util (S, m, n, 0);
    }
    
    
    long long int util( int S[], int m, int n, int pos = 0)
    {
        if (n==0) return 1;
        if (n<0) return 0;
        
        if (v[n][pos] != -1) return v[n][pos];
        
        long long int res=0;
        for (int i=pos; i<m; i++) {
            res += util (S, m, n-S[i], i);
        }
        return v[n][pos] = res;
    }
};

// Bottom up iterative approach: Dynamic programming
class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
        long long int dp[m+1][n+1];
        
        for (long long int i=0; i<m+1; i++) {
            for (long long int j=0; j<n+1; j++) {
                if (j==0) {
                    dp[i][j] = 1;
                    continue;
                }
                if (i==0) {
                    dp[i][j] = 0;
                    continue;
                }
                
                if (S[i-1] <= j) {
                    dp[i][j] = dp[i][j-S[i-1]] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        } 
        return dp[m][n];
    }
};