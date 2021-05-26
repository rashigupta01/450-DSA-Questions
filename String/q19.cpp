// Niave approach
int lps(string s) {
    
    int res = 0;
    string pre = "", suf = "";
    int ppos=0, spos=s.size()-1;
    
    while (ppos<s.size()-1) {
        pre += s[ppos++];
        suf = s[spos--] + suf;
        if (pre == suf) res = ppos;
    }
    return res;
}