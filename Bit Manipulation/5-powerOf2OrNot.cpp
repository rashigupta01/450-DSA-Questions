#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, count=0;
    cin>>n;
    n = n&(n-1);
    if(n==0) {
        cout<<"It is a power of 2";
    } else {
        cout<<"It is not a power of 2";
    }
}