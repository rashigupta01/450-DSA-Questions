// Approach 1: Using two nested loops check every subarray and increment the counter if sum is zero. (TC-O(n^2) SC-O(1)) 

// Approach 2: First find prefix vector then hash its values one by one in increase the counter by the no of previous occurances
// of current sum. (TC-O(n) SC-O(n))
ll findSubarray(vector<ll> arr, int n ) {
    vector<ll> pre(n);
    pre[0]=arr[0];
    for(ll i=1; i<n; i++) {
        pre[i] = pre[i-1] + arr[i];
    }
    ll count=0;
    for(ll i=0; i<n; i++) {
        count += (pre[i]==0);
    }
    unordered_map<ll, ll> m;
    for(ll i=0; i<n; i++) {
        
        count += m[pre[i]];
        m[pre[i]]++;
    }
    return count;
}
