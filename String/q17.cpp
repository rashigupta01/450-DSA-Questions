// Refer https://www.geeksforgeeks.org/word-break-problem-dp-32/ for various approaches
int wordBreak(string A, vector<string> &B) {
    unordered_map <string, bool> dict;
    for (int i=0; i<B.size(); i++) {
        dict[B[i]] = true;
    }
    bool dp[A.size()+1];
    dp[0] = true;
    for (int i=1; i<=A.size(); i++) {
        dp[i] = false;
        for (int j=0; j<i; j++) {  // confirm
            string s1 = A.substr(0, j);
            string s2 = A.substr(j, i-j);
            
            if (dict[s2] && dp[j]) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[A.size()];
}

// 