// DP approach 
ll FindMaxSum(ll arr[], ll n)
{
    ll dp[n+1];

    dp[0] = 0;
    dp[1] = arr[0];
    
    for (ll i=2; i<=n; i++) {
        dp[i] = max (dp[i-1], dp[i-2] + arr[i-1]);
    }   
    return dp[n];
}

// On gfg: maintain two var excl and incl, basically they are maintaining dp[i-1] and dp[i-2]
// reducing the space complexity to O(1)