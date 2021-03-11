// how i did
void wordBreakBack(vector<string>& dict, string s, vector<string> &result, int i=0, string current = "") {
    if (i==s.size()) {
        current.pop_back();
        result.push_back(current);
    }
    string word = "";
    for (int j=i; j<s.size(); j++) {
        word+=s[j];
        for (int m=0; m<dict.size(); m++) {
            if(dict[m] == word) {
                wordBreakBack(dict, s, result, j+1, current+word+" ");
                break;
            }
        }
    }
}

vector<string> wordBreak(int n, vector<string>& dict, string s)
{
    vector<string> result;
    wordBreakBack(dict, s, result);
    return result;
}


// On gfg : https://www.geeksforgeeks.org/word-break-problem-using-backtracking/
void wordBreak(string str, int n, string result="") {

    for (int i=1; i<=n; i++) {

        string prefix = str.substr(0, i);
        if (dictionaryContains(prefix)) {
            
            if (i == n) {
                result += prefix;
                cout << result << endl;
                return;
            }
            wordBreakUtil(str.substr(i, n-i), n-i, result + prefix + " ");
        }
    }      
}