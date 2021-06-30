// My approach : unbounded knapsack
class Solution{

	public:
	int minimumCost(int cost[], int N, int W) 
	{ 
	    int dp[N+1][W+1];
	    memset (dp, -1, sizeof(dp));
	    for (int i=0; i<=N; i++) dp[i][0] = 0;
	    
	    for (int i=1; i<=N; i++) {
	        for (int j=1; j<=W; j++) {
	            dp[i][j] = dp[i-1][j];
	            
	            if (cost[i-1]!=-1 && i<=j && dp[i][j-i] != -1) {
	                int consider = cost[i-1] + dp[i][j-i];
	                if (dp[i][j]==-1) dp[i][j] = consider;
	                else dp[i][j] = min (dp[i][j], consider);
	            }
	        }
	    }
	    return dp[N][W];
	} 
};

// Another approach : Rod cutting (space optimized)