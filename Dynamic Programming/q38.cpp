
int wordBreak(string A, vector<string> &B) {
    unordered_map <string, bool> dict;
    for (int i=0; i<B.size(); i++) {
        dict[B[i]] = true;
    }
    bool dp[A.size()+1];
    dp[0] = true;
    for (int i=1; i<=A.size(); i++) {
        dp[i] = false;
        for (int j=0; j<i; j++) {
            string s = A.substr(j, i-j);
            
            if (dict[s] && dp[j]) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[A.size()];
}