#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, count=0, pos=0;
    cin>>n;
    while(n>=(1<<pos)) {
        int extra = ((n+1)%(1<<(pos+1))-(1<<pos));
        count += (1<<pos)*((n+1)/(1<<(pos+1))) + (extra>0 ? extra:0);
        pos++;
    }
    
    cout<<count;
}