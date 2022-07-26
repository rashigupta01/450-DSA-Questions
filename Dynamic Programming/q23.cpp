
vector<vector<int>> memo;
int egg (int n, int k) 
{
    if (k==0) return 0;
    if (n==1) return k;
    
    if (memo[n][k]!=-1) return memo[n][k];
    
    int ans = INT_MAX;
    for (int i=1; i<=k; i++) {
        int t1 = egg (n-1, i-1), t2 = egg (n, k-i);
        int cur = 1 + max (t1, t2);
            
        ans = min (ans, cur);
    }
    return memo[n][k] = ans;
}
int eggDrop (int n, int k) {
    memo = vector<vector<int>> (n+1, vector<int> (k+1, -1));
    return egg (n, k);
}