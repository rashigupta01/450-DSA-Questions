// Reccursion
int countFriendsPairings(int n) 
{ 
    if (n<=1) return 1;
    return countFriendsPairings(n-1) + (n-1) * countFriendsPairings(n-2);   // issue of overflow will be there
}

// Tabulation
int MOD = 1000000007;
int countFriendsPairings(int n) 
{ 
    int dp[n+1];
    dp[0] = dp[1] = 1;
    for(int i=2; i<=n; i++) {
        dp[i] = (dp[i-1] + ((long)(i-1)*(long)dp[i-2])%MOD )%MOD;
    }
    return dp[n];
}