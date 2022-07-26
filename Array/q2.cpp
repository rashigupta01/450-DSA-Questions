/*

Approach 1:
initialize max_element with INT_MAX and iterate over the array while keep updating the variable max_element (same for min_element)
No of comparisions : 2*n
Small modification - initialize max_element and min_element with first two elements 
No of comparisions : 1 + 2(n-2)
*/
pair<long long, long long> getMinMax(long long a[], int n) {
    long long mn=a[0], mx=a[0];
    for (int i=1; i<n; i++) {
        mn = min (mn, a[i]);
        mx = max (mx, a[i]);
    }
    return {mn, mx};
}
/*

Approach 2: (Tournament Method)
use divide and conquer approach
No of comparisions : 3n/2 -2   // if n is power of two

Approach 3: (Compare in Pairs)
If n is odd then initialize min and max as first element else as minimum and maximum of the first two elements. 
For rest of the elements, pick them in pairs and compare their maximum and minimum with max and min respectively. 
No of comparisions : 3*(n-1)/2      // n is odd
                     3n/2 -2        // n is even

*/