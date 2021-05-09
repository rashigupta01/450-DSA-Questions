class Solution{
public:
    int memo[101][101];

    int util (int arr[], int n, int i, int j) {
        
        if (i>=j) return 0;
        if (memo[i][j]!=-1) return memo[i][j];
        
        int result = INT_MAX;
        
        for (int k=i; k<j; k++) {
            int temp = util(arr, n, i, k) + util (arr, n, k+1, j) + arr[i-1]*arr[k]*arr[j];
            result = min (result, temp);
        }
        return memo[i][j] = result;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        memset(memo, -1, sizeof(memo));
        return util (arr, N, 1, N-1);
    }
};