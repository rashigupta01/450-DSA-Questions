// https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/


// Divide the string into two parts and swap each element of first part with the elements of second part
// can be implemented in iterative and reccursive manner. (TC-O(n))
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i=0; i<s.size()/2; i++) {
            char temp = s[i];
            s[i] = s[s.size() - 1 - i];
            s[s.size() - 1 - i] = temp;
        }
    }
};