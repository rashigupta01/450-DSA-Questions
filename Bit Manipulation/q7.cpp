#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main() {
    int x, y, l, r;
    cin>>x>>y>>l>>r;

    /*
     * Method 1
    for (int i = l; i <= r; i++)
    {
        if(y&(1<<(i-1))) {
            x |= 1<<(i-1);
        }
    }
    cout<<x;
    */

    // Method 2
    x = x | (y&((1<<(r-l+1)-1)<<(l-1)));
    cout<<x;
}