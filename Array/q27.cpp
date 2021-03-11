#include <bits/stdc++.h>
using namespace std;

// Approach 1: For all elements of arr2 check if it exists in arr1 using two loops. (TC-O(n*m))

// Approach 2: Instead of doing linear search in arr1, we can first sort arr1 and for each element in arr2 do binary search in arr1.
// (TC-O((m+n)Logm))

// Approach 3: Hashing- hash all the elements of arr1 and for each element in arr2 check if it exists. (TC-O(n+m))

// **************************** Take care of Duplicates ******************
// Approach 4: sort both arrays using two pointer if arr2 is a part of arr1 or not (TC-O(mLogm + nLogn))
int main()
{
    int t;
    cin>>t;
    while(t--) {
        int m, n;
        cin>>m>>n; 
        vector<int> arr1(m);
        vector<int> arr2(n);
        for(int i=0; i<m; i++) cin>>arr1[i];
        for(int i=0; i<n; i++) cin>>arr2[i];
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        int pos1=0, pos2=0;
        while(pos1<m && pos2<n) {
            if(arr1[pos1]<arr2[pos2]) {
                pos1++;
            } else if(arr1[pos1]>arr2[pos2]) {
                break;
            } else {
                pos1++; pos2++;
            }
        }
        if(pos2==n) cout<<"Yes"<<endl;
        else cout<<"No\n";
    }
	return 0;
}

// Approach 5: create a frequency table for arr1. Iterate through arr2, and keep decreasing the count in frequency table of arr1.
// If for any element count is zero return false. (TC-O(n+m))