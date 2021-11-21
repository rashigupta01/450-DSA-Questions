// this gave tle on leetcode : overlapping subproblem issue
bool match(string wild, string pattern, int p1=0, int p2=0) {

    if(p1==wild.size() && p2 == pattern.size()) return true;
    if(p1==wild.size()) return false;
    
    if (wild[p1]=='*') {
        for (int i = p2; i<=pattern.size(); i++) {
            if (match (wild, pattern, p1+1, i)) return true;
        }
        return false;
    } 
    
    if (p2 == pattern.size()) return false;
    if (wild[p1]=='?') {
        return match(wild, pattern, p1+1, p2+1);
    } else {
        if (wild[p1] == pattern[p2]) return match (wild, pattern, p1+1, p2+1);
        else return false;
    }
}

// gfg editorial code : dp code
bool isMatch(string str, string pattern, int n=0, int m=0) {
    if (pattern.size() == 0) return (str.size() == 0);

    bool lookup[str.size() + 1][pattern.size() + 1];
    memset(lookup, false, sizeof(lookup));
    lookup[0][0] = true;

    // Only '*' can match with empty string
    for (int j = 1; j <= pattern.size(); j++)
        if (pattern[j - 1] == '*')
            lookup[0][j] = lookup[0][j - 1];

    // fill the table in bottom-up fashion
    for (int i = 1; i <= str.size(); i++) {
        for (int j = 1; j <= pattern.size(); j++) {
            if (pattern[j - 1] == '*')
                lookup[i][j] = lookup[i][j - 1] || lookup[i - 1][j];

            else if (pattern[j - 1] == '?' || str[i - 1] == pattern[j - 1])
                lookup[i][j] = lookup[i - 1][j - 1];

            else
                lookup[i][j] = false;
        }
    }

    return lookup[str.size()][pattern.size()];
}