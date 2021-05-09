class Solution {
	public:
	int LongestRepeatingSubsequence(string str){
		int x = str.size();
        int dp[x+1][x+1];
        memset(dp, 0, sizeof(dp));
        for (int i=1; i<=x; i++) {
            for (int j=1; j<=x; j++) {
                if (str[i-1] == str[j-1] && i!=j) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max (dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[x][x];
	}
};