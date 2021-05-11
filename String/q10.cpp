// Approach 1 : 
// pick ith letter , do not pick ith letter

// Approach 2 :
// Bit masking
vector<string> AllPossibleStrings(string s){
    vector<string> res;
    int n = s.size();
    for (int i = 1; i < 1<<n; i++)
    {
        string str="";
        for (int j = 0; j < n; j++)
        {
            if(i&(1<<j)) {
                str.push_back(s[j]);
            }
        }
        res.push_back(str);
    }
    sort (res.begin(), res.end());
    return res;
}

// Refer: https://www.geeksforgeeks.org/print-subsequences-string/ for more approaches