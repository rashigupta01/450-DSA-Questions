// Memoization : Reccursion
class Solution {
    
    public:
    vector<vector<int>> v;
    
    int util (int W, int wt[], int val[], int n) {

        if (n==0 || W==0) return 0;
        
        if (v[n][W] != -1) return v[n][W];
        
        int ans=0;
        if (wt[n-1] <= W) {
            ans = max (val[n-1] + util(W-wt[n-1], wt, val, n-1), 
            util (W, wt, val, n-1));
        }
        else {
            ans = util (W, wt, val, n-1);
        }
        v[n][W] = ans;
        return ans;
    }
    
    int knapSack(int W, int wt[], int val[], int n) { 
        v = vector<vector<int>> (n+1, vector<int> (W+1, -1));
        return util (W, wt, val, n);
    }
};

// Tabulation method
class Solution {
    
    public:
    
    int knapSack(int W, int wt[], int val[], int n) { 
        vector<vector<int>> v (n+1, vector<int> (W+1, -1));
        for (int i=0; i<=n; i++) {
            v[i][0] = 0;
        } 
        for (int i=0; i<=W; i++) {
            v[0][i] = 0;
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=W; j++) {
                if (wt[i-1] <= j) {
                    v[i][j] = max (val[i-1] + v[i-1][j-wt[i-1]], v[i-1][j]);
                } else {
                    v[i][j] = v[i-1][j];
                }
            }
        }
        return v[n][W];
    }
};