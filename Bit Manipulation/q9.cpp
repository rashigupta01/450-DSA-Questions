#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int temp = n, pos=0, square=0;
    while(temp) {
        int curr = temp&1;
        temp >>= 1;
        if(curr)
            square += n<<pos;
        pos++;
    }
    cout<<square;
}