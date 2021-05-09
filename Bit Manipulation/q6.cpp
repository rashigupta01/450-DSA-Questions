#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, count=0, pos;
    cin>>n;

    pos = log2(n&(-n)) + 1;
    n = n&(n-1);
    if(n==0) {
        cout<<pos;
    } else {
        cout<<-1;
    }
}