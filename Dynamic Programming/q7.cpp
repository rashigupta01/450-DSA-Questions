class Solution {
  public:
    int editDistance(string s, string t) {
        int x = s.size();
        int y = t.size();
        int dp[x+1][y+1];
        memset(dp, 0, sizeof(dp));
        
        for (int i=0; i<=x; i++) {
            for (int j=0; j<=y; j++) {
                if (i==0) {
                    dp[i][j] = j;
                    continue;
                }
                if (j==0) {
                    dp[i][j] = i;
                    continue;
                }
                if (s[i-1]==t[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min (min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
                }
            }
        }
        return dp[x][y];
    }
};