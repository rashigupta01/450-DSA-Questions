// My approach : prefix sum
vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
    
    vector<long long int> pre(n);
    
    pre[0] = 1;
    for (int i=1; i<n; i++) {
        pre[i] = pre[i-1]*nums[i-1];
    }
    
    long long int suf = 1;
    for (int i=n-2; i>=0; i--) {
        suf *= nums[i+1];
        pre[i] = pre[i]*suf;
    }
    
    return pre;  
}

// Mathematical approaches :
// i) output[i] = antilog((log(a[0]) + log(a[1]) + .. + log(a[n-1])) - log(a[i]))
// ii) output[i] = (product * pow(a[i], -1))    
 