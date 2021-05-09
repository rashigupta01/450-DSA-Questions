// Memoization
#define MOD 1000000007

class Solution{
public:

    int memo [1001][801];
    
    int util (int n, int r) {
        if (r==0) return 1;
        if (n<r) return 0;
        
        if (memo[n][r] != -1) return memo[n][r];
        
        return memo[n][r] = (r*util (n-1, r-1) + util (n-1, r))%MOD;
    }
    
    int nPr(int n, int r){
    
        memset(memo, -1, sizeof(memo));
        return util (n, r);
    }
};

// Tabulation
#define MOD 1000000007

class Solution{
public:

    int memo [1001][801];
    
    int nPr(int n, int r){
    
        memset(memo, -1, sizeof(memo));
        
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=r; j++) {
                if (j==0) memo[i][j] = 1;
                else if (i<j) memo[i][j] = 0;
                else {
                    memo[i][j] = (memo[i-1][j] + j*memo[i-1][j-1])%MOD;
                }
            }
        }
        return memo[n][r];
    }
};

// * Best approach:
// A O(n) time and O(1) extra space  
int PermutationCoeff(int n, int k)
{
    int P = 1;
 
    // Compute n*(n-1)*(n-2)....(n-k+1)
    for (int i = 0; i < k; i++)
        P *= (n-i) ;
 
    return P;
}