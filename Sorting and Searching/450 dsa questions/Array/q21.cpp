
// Approach 1: Brute force - try all possible subarrays and check their sum in two nested loops

// Approach 2: find prefix of array, if any element is being repeated return true else false
bool subArrayExists(int arr[], int n)
{
    int prefix[n+1];
    prefix[0] = 0;
    for(int i=1; i<=n; i++) prefix[i] = prefix[i-1] + arr[i-1];
    unordered_map<int, bool> m;
    for(int i=0; i<=n; i++) {
        if(m[prefix[i]]) {
            return true;
        } else {
            m[prefix[i]] = true;
        }
    }
    return false;
}