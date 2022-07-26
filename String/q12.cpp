// used reccursion, can be memoized, zyada hi dimag laga liya simple se question mein
// O(n*n) once memoized
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

bool balenced (string s, int i, int j) {
    int c = 0;
    for (int k=i; k<=j; k++) {
        c += s[k]=='1' ? 1 : -1;
    }
    return c==0;
}

int splits (string s, int i, int j) {
    if (i>=j) return -1;
    if (i==j-1) {
        if (s[i] != s[j]) return 1;
        else return -1;
    }
    
    int split = 0;
    for (int ptr=i; ptr<j; ptr++) {
        int s1 = splits(s, i, ptr);
        int s2 = splits(s, ptr+1, j);
        split = max (split, s1+s2);
    }
    if (split) return split;
    if (balenced(s, i, j)) return 1;
    else return -1;
}

int main() {
    
    string s = "0100110101";
    cout << splits (s, 0, s.size()-1);
}

// Simple O(n) approach
// keep a counter, increment for 1 decrement for 0, as counter becomes 0 increment result
// https://www.geeksforgeeks.org/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/
int maxSubStr(string str){
    int res=0, cur = 0;
    for (int i=0; i<str.size(); i++) {
        cur += str[i]=='0' ? 1 : -1;
        res += cur==0;
    }
    return cur==0 ? res : -1;
}