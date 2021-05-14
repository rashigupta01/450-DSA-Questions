#define ll long long int
class Solution {
public:
vector<vector<int>> res;

void util ( vector<vector<ll>> &nl, int i, int j) {
    if (nl[i][j]==-1) {
        res.push_back({i, j});
        return;
    }
    util (nl, i, nl[i][j]);
    util (nl, nl[i][j]+1, j);
}

vector<vector<int>> solveWordWrap(vector<int>nums, int wd) 
{ 
    int n = nums.size();
    vector<vector<ll>> dp(n+1, vector<ll>(n+1));
    vector<vector<ll>> nl(n+1, vector<ll>(n+1));
    // ll dp[n+1][n+1], nl[505][505];
    ll pre[n+1];
    pre[0] = 0;
    for (ll i=0; i<n; i++) {
        pre[i+1] = pre[i]+(ll)nums[i];
    }
    for (int l=1; l<=n; l++) {
        for (int i=1; i<=n-l+1; i++) {
            int j = i+l-1;
            int width = pre[j]-pre[i-1]+(j-i);
            if (width <= wd) {
                dp[i][j] = j==n ? 0 : pow(wd-width, 3);
                nl[i][j] = -1;
                continue;
            }
            dp[i][j] = INT_MAX;
            for (int k=i; k<j; k++) {
                if (dp[i][k] + dp[k+1][j] < dp[i][j]) {
                    dp[i][j] = dp[i][k] + dp[k+1][j];
                    nl[i][j] = k;
                }
            }
        }
    }
    util (nl, 1, n);
    return res;
} 
};
