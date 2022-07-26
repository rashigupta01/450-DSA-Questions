// my approach: a bit different from gfg
long long int  countPS(string str)
{
    int n = str.size();
    int i, j, cl;
    long long int L[n][n];  // Create a table to store results of subproblems
    int MOD = 1000000007;
    
    memset(L, 0, sizeof(L));
    for (i = 0; i < n; i++) L[i][i] = 1;
    
    for (cl=2; cl<=n; cl++) {
        for (i=0; i<n-cl+1; i++) {
            j = i+cl-1;
            if (str[i] == str[j] && cl == 2) L[i][j] = 1;
            else if (str[i] == str[j]) L[i][j] = L[i+1][j-1]*2;
            else L[i][j] = (L[i][j-1] + L[i+1][j] - L[i+1][j-1]);
            
            L[i][j] %= MOD;
        }
    }
    return L[0][n-1];
}