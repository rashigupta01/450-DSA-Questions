#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using 2 nested loops check all the pairs if the sum of any pair is k increment the count. (TC-O(n^2) SC-O(1))

// Approach 2: Sort the array. Using two pointer approach count the possible pairs. (TC-O(nlogn) SC-O(1))
class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        sort(arr, arr+n);
        
        int l=0, r=n-1, result=0;
        while(l<r) {
            if(arr[l]+arr[r] == k) {
                int temp = r;
                while(temp>l && arr[temp] == arr[r]) {
                    temp--;result++;
                }
                l++;
            } else if (arr[l]+arr[r] < k) {
                l++;
            } else {
                r--;
            }
        }
        return result;
    }
};

// Approach 4: Sort and apply binary search for each value. (TC-O(nlogn) SC-O(1))

// Approach 3: Hash all the elements in the array. In second iteration do result += count[a[i]] * count[k-a[i]]. Return result/2. 
// (TC-O(n) SC-O(n))