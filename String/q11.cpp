vector<string> res;
void util (string S, int idx) {
    
    if (idx==S.size()) {
        res.push_back(S);
        return;
    }
    for (int i=idx; i<S.size(); i++) {
        swap(S[i], S[idx]);
        util (S, idx+1);
        swap(S[i], S[idx]);
    }
}
vector<string>find_permutation(string S)
{
    util (S, 0);
    sort(res.begin(), res.end());
    return res;
}

// If string contains duplicates : https://www.geeksforgeeks.org/print-all-permutations-of-a-string-with-duplicates-allowed-in-input-string/
// did not understood the above link refer it in fresh mind