vector<int> dp;
int util (vector<int> nums, int k, int pos) {
    
    if (pos == nums.size()) return 0;
    if (dp[pos]!= -1) return dp[pos];
    
    int cur = nums[pos];
    int i = pos;
    int ans = INT_MAX;
    while (cur<=k) {
        
        ans = min (ans, (k-cur)*(k-cur) + util (nums, k, i+1));
        i++;
        if (i==nums.size()) {
            return dp[pos] = 0;
        }
        cur += 1 + nums[i];
    }
    return dp[pos] = ans;
}
int solveWordWrap(vector<int>nums, int k) 
{ 
    dp =  vector<int> (nums.size(), -1);
    return util (nums, k, 0);
} 