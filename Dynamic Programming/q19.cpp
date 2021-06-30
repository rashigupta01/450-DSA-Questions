// similar approach as of lis
class Solution{

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    int dp[n];
	    
	    int res = INT_MIN;
	    for (int i=0; i<n; i++) {
	        dp[i]=arr[i];
	        for (int j=0; j<i; j++) {
	            if (arr[j]<arr[i]) {
	                dp[i] = max (dp[i], dp[j]+arr[i]);
	            }
	        }
	        res = max (res, dp[i]);
	    }
	    return res;
	    
	}  
};