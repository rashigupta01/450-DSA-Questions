#include <bits/stdc++.h>
using namespace std;

string say (string s) {
    string result = "";
    for (int i=0; i<s.size(); ) {
        char letter = s[i];
        int count=0;
        while (i<s.size() && s[i]==letter) {
            count++; i++;
        }
        result += to_string (count) + letter;
    }
    return result;
}

string countAndSay(int n) {
    if (n==1) return "1";
    
    return say(countAndSay(n-1));
}

int main () {
    int n;
    cin>>n; 
    cout << countAndSay (n);
    return 0;
}