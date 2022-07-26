// My approach 
// Iterate through each element of the string, considering it the center expand on both sides until it is a palindrome
// All odd palindromes are covered. Now to cover even length palindromes iterate through the string and consider the 
// center as a pair 

// dp approach : https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
string longestPalin (string S) {
    int n = S.size();
    vector<vector<bool>> dp (n, vector<bool>(n, false));
    for (int i=0; i<n; i++) {
        dp[i][i] = true;
    }
    int mx = 0, mr = 0, mc = 0;
    for (int i=1; i<n; i++) {
        for (int j=0; j<n-i; j++) {
            int r = j;
            int c = j+i;
            if (S[r]==S[c]) {
                if (abs(r-c) == 1) {
                    dp[r][c] = true;
                } else {
                    dp[r][c] = dp[r+1][c-1];
                }
            }
            if (dp[r][c]) {
                if (c-r > mx || (c-r==mx && r<mr)) {
                    mc = c;
                    mr = r;
                    mx = c-r;
                }
            }
        }
    }
    return S.substr(mr, mc-mr+1);
}