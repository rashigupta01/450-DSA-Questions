// DP tabulation approach : O(N*N)
class Solution {
public:
    unordered_map<string, int> memo;
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sorted (nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());
        
        int n = nums.size();
        vector<int> second;
        second.push_back(sorted[0]);
        for (int i=1; i<n; i++) {
            if(sorted[i] != sorted[i-1]) {
                second.push_back(sorted[i]);
            }
        }
        
        int m = second.size();
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (nums[i-1] == second[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max (dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
};