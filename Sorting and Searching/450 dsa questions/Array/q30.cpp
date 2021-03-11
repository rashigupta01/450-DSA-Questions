
// Approach 1: sort the array, for all subarrays of size m print the minimum difference between the max and min elements. (TC-O(nlogn))
int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n; 
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        int m;
        cin>>m;
        int result = INT_MAX;
        sort(a.begin(), a.end());
        for(int i=0; i<n-m+1; i++) {
            result = min(result, a[i+m-1]-a[i]);
        }
        cout<<result<<endl;
    }
	return 0;
}