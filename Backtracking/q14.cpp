#include <bits/stdc++.h>
using namespace std;

void permutation (string s, int index=0) {
    if (index == s.size()) {
        cout<<s<<endl;
    }

    for (int i=index; i<s.size(); i++) {
        swap (s[i], s[index]);
        permutation(s, index+1);
        swap (s[i], s[index]);
    }
}

int main () {
    permutation("abc");
    return 0;
}

// If string contains duplicates : https://www.geeksforgeeks.org/print-all-permutations-of-a-string-with-duplicates-allowed-in-input-string/
// did not understood the above link refer it in fresh mind
vector<string> res;
void util (string S, int idx) {
    
    if (idx==S.size()) {
        res.push_back(S);
        return;
    }
    unordered_map<char, int> check;
    for (int i=idx; i<S.size(); i++) {
        if ( check[S[i]]!=0) continue;
        swap(S[i], S[idx]);
        check[S[idx]]++;
        util (S, idx+1);
        swap(S[i], S[idx]);
    }
}
vector<string>find_permutation(string S)
{
    sort(S.begin(), S.end());
    util (S, 0);
    sort(res.begin(), res.end());
    return res;
}