#include<bits/stdc++.h>
using namespace std;

// Approach 1: in two nested loops find the total no of inversions

// Approach 2 : use enhanced merge sort, following is my code
// Refer gfg for a bit different way of calculating inversions in merge function
long long merge (long long arr[], long long s, long long m, long long e) {
    long long inversions=0;
    long long count=0;
    int i=s, j=m+1, k=0;
    long long array[e-s+1];
    while (i<=m && j<=e) {
        if (arr[j] < arr[i]) {
            array[k++] = arr[j++];
            count++;
        } else {
            inversions += count;
            array[k++] = arr[i++];
        }
    }
    while (i<=m) {
        inversions += count;
        array[k++] = arr[i++];
    }
    while (j<=e) {
        array[k++] = arr[j++];
    }
    for (int i=s; i<=e; i++) {
        arr[i] = array[i-s];
    }
    return inversions;
}

long long int mergeSort (long long arr[], long long s, long long e) {
    
    if (s>=e) return 0;
    
    long long mid = (s+e)/2;
    
    long long result = 0;
    result += mergeSort (arr, s, mid);
    result += mergeSort (arr, mid+1, e);
    result += merge (arr, s, mid, e);
    
    return result;
}
long long int inversionCount(long long arr[], long long N)
{
    return mergeSort (arr, 0, N-1);
}

// ! Following is a wrong approach i tried : https://practice.geeksforgeeks.org/viewSol.php?subId=2f7ee6c1df6f1e443f6d572a58a8bbe1&pid=701226&user=guptarashi2001
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