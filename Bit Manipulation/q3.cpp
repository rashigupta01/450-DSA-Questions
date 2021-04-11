#include<bits/stdc++.h>
using namespace std;

// count the set bits in xor of a and b
int main() {
    int a, b, count=0;
    cin>>a>>b;
    int temp = a^b;
    while (temp) {
        count++;
        temp = temp&(temp-1);
    }
    cout<<count;
}