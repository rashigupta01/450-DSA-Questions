// my approach : same on gfg
int util (vector<pair<int, int>> &v, int s, int e, vector<vector<int>> &dp, vector<int> &presum) {
    if (e<s) return 0;
    if (dp[e][s]!=-1) return dp[e][s];
    
    int ans = INT_MAX;
    for (int i=s; i<=e; i++) {
        ans = min (ans, util (v, s, i-1, dp, presum) + util (v, i+1, e, dp, presum));
    }
    ans += presum[e+1] - presum[s];
    return dp[e][s] = ans;
}
int optimalSearchTree(int keys[], int freq[], int n)
{
    vector<pair<int, int>> v;
    for (int i=0; i<n; i++) {
        v.push_back({keys[i], freq[i]});
    }
    sort (v.begin(), v.end());
    vector<vector<int>> dp (n, vector<int> (n, -1));
    vector<int> presum(n+1, 0);
    for (int i=1; i<=n; i++) presum[i] = presum[i-1] + v[i-1].second;

    return util (v, 0, n-1, dp, presum);
}