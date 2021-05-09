// sort arr and dep the find no of platforms at any instant and store the max of this in result;
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr+n);
        sort(dep, dep+n);
        
        int parr = 0, pdep=0;
        int maxplat = 0, platforms = 0;
        while (parr<n && pdep<n) {
            while (parr<n && arr[parr] <= dep[pdep]) {
                platforms++;
                parr++;
            }
            maxplat = max (maxplat, platforms);
            if (parr==n) break;
            while (pdep<n && dep[pdep] < arr[parr]) {
                platforms--;
                pdep++;
            }
        }
        return maxplat;
    }
};