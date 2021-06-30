
// refer for iterative or bottom up approach
// https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/

// my reccursive approach
class Solution{
public:
    int dp[205][205][2];
    
    int util (string s, int start, int end, bool val) {
        if (dp[start][end][val] != -1) return dp[start][end][val];
        
        if (start == end) {
            if (val) return dp[start][end][val] = s[start] == 'T';
            else return dp[start][end][val] = s[start] == 'F';
        }
        
        int total = 0;
        for (int i=start+1; i<end; i+=2) {
            
            int ltrue = dp[start][i-1][1]==-1 ? util (s, start, i-1, true) : dp[start][i-1][1];
            int lfalse = dp[start][i-1][0]==-1 ? util (s, start, i-1, false) : dp[start][i-1][0];
            int rtrue = dp[i+1][end][1]==-1 ? util (s, i+1, end, true) : dp[i+1][end][1];
            int rfalse = dp[i+1][end][0]==-1 ? util (s, i+1, end, false) : dp[i+1][end][0];
            
            if (s[i]=='&') {
                if (val) {
                    total += ltrue * rtrue;    
                } else {
                    total += ltrue*rfalse + lfalse*rtrue + lfalse*rfalse;
                }
                
            } else if (s[i]=='|') {
                if (val) {
                    total += ltrue*rtrue + ltrue*rfalse + lfalse*rtrue;
                } else {
                    total += lfalse * rfalse;
                }
            } else if (s[i] == '^') {
                if (val) {
                    total += ltrue*rfalse + lfalse*rtrue;
                } else {
                    total += ltrue*rtrue + lfalse*rfalse;
                }
            }
        }
        return dp[start][end][val] = (total)%1003;
    }

    int countWays(int N, string S){
        memset (dp, -1, sizeof dp);
        return util (S, 0, N-1, true);
    }
};