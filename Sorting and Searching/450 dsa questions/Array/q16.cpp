#include<bits/stdc++.h>
using namespace std;

// Approach 1: in two nested loops find the total no of inversions

long long int binarySearch (long long int a[], long long N, long long int key) {
    int low=0, high = N-1, ans = -1;
    while(low<=high) {
        long long int mid = (low + high)/2;
        if(a[mid] == key) {
            ans =  mid;
            high = mid-1;
        }
        else if (a[mid]>key) high = mid-1;
        else low = mid+1;
    }
    return ans;
}

long long int inversionCount(long long arr[], long long N)
{
    long long temp[N];
    copy(arr, arr+N, temp);
    sort(temp, temp+N);
    for (long long int  i = 0; i < N; i++)
    {
        cout<<temp[i]<<" ";
    }
    cout<<endl;
    
    long long int result = 0;
    for(int i=0; i<N; i++) {
        long long int index = binarySearch(temp, N, arr[i]);
        cout<<index<<" ";
        result += index>i ? index-i : 0;
    }
    return result;
}

int main() {
    long long int n;
    cin>>n;
    long long int a[n];
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    cout<<inversionCount(a, n);
}