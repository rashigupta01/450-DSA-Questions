#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, count=0;
    cin>>a>>b;
    while(a || b) {
        count += (a&1)^(b&1);
        a >>= 1;
        b >>= 1;
    }
    cout<<count;
}