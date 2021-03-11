// Approach 1: store the digits as vector of digits in reverse order and perform multiplication as in elementry steps 

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int max_num = 1001;
    
    vector<vector<int>> fact(max_num);
    int dig, i, j;
    fact[0].push_back(1);
    for(i=1; i<max_num; i++) {
        int carry = 0;
        for(j=0; j<fact[i-1].size(); j++) {
            dig = fact[i-1][j] * i + carry;
            fact[i].push_back( dig%10 );
            carry = dig/10;
        }
        while(carry!=0) {
            fact[i].push_back( carry%10 );
            carry = carry / 10;
        }
    }
    int t;
    cin>>t;
    while(t--) {
        int n, sum = 0;
        cin>>n;
        for(i=fact[n].size()-1; i>=0; i--) {
            cout<<fact[n][i];
        }
        cout<<endl;
    }
    return 0;
}