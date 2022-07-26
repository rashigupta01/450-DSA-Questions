
// difficult to convert this approach into bottom-up
int lps(string seq, int i, int j, vector<vector<int>> &dp)
{
    if (i==j) return 1;
    if (i>j) return 0;
    if (dp[i][j]!=-1) return dp[i][j];

    int found = -1;
    for (int k = i; k<j; k++) {
        if (seq[k] == seq[j]) {
            found = k;
            break;
        }
    }
    if (found!= -1) return dp[i][j] = max (lps(seq, i, j-1, dp), lps(seq, found+1, j-1, dp)+2);
    return dp[i][j] = lps(seq, i, j-1, dp);
}
int longestPalinSubseq(string A) {
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return lps (A, 0, n-1, dp);
}

// simpler approach on gfg editorial
/*
-> Every single character is a palindrome of length 1
L(i, i) = 1 for all indexes i in given sequence

-> IF first and last characters are not same
If (X[i] != X[j])  L(i, j) =  max{L(i + 1, j),L(i, j - 1)} 

-> If there are only 2 characters and both are same
Else if (j == i + 1) L(i, j) = 2  

-> If there are more than two characters, and first and last 
   characters are same
Else L(i, j) =  L(i + 1, j - 1) + 2 
*/

// bottom up (tabulation) approach
int lps(char *str) {
   int n = strlen(str);
   int i, j, cl;
   int L[n][n];  // Create a table to store results of subproblems
 
   for (i = 0; i < n; i++) L[i][i] = 1;
 
    for (cl=2; cl<=n; cl++) {
        for (i=0; i<n-cl+1; i++) {
            j = i+cl-1;
            if (str[i] == str[j] && cl == 2) L[i][j] = 2;
            else if (str[i] == str[j]) L[i][j] = L[i+1][j-1] + 2;
            else L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }
    return L[0][n-1];
}