// My code: 
class Solution{
	public:
	long long getCount(int N)
	{
	    long long int dp[N][10];
	    memset(dp, 0, sizeof dp);
	    
	    long long int left, right, down, up;
	    long long result = 0;
	    for (int i=0; i<N; i++) {
	        for (int j=0; j<10; j++) {
    	        if (i==0) dp[i][j] = 1;
	            else {
	                if (j%3==0) left = -1;
	                else left = j-1;
	                
	                if ((j+1)%3==0 || j==9) right = -1;
	                else right = j+1;
	                
	                if (j<3) up = -1;
	                else if (j==9) up = 7;
	                else up = j-3;
	                
	                if (j<6) down = j+3;
	                else if (j==7) down = 9;
	                else down = -1;
	                
	                long long int cleft = left==-1 ? 0 : dp[i-1][left];
	                long long int cright = right==-1 ? 0 : dp[i-1][right];
	                long long int cdown = down==-1 ? 0 : dp[i-1][down];
	                long long int cup = up==-1 ? 0 : dp[i-1][up];
	                
	                dp[i][j] = dp[i-1][j] + cup + cdown + cleft + cright;
	            }
	            if (i==N-1) {
	                result += dp[i][j];
	            }
	        }
	    }
	    return result;
	}
};