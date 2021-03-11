// https://www.geeksforgeeks.org/count-set-bits-in-an-integer/

// Solved by Brian Kernighan’s Algorithm

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, count=0;
    cin>>n;
    while(n) {
        n = n&(n-1);
        count++;
    }
    cout<<count;
}