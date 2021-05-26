class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k) {
        sort (a, a+n);
        int negate = k, minval=-1;
        for (int i=0; i<n && negate; i++) {
            if (a[i] < 0) {
                a[i] = -a[i];
                negate--;
            } else {
                if (i) minval = min (a[i], a[i-1]);
                else minval = a[i];
                break;
            }
        }
        long long int sum = 0;
        for (int i=0; i<n; i++) sum += (long long int)a[i];
        if (negate&1) {
            if (minval == -1) minval = a[n-1];
            return sum - (long long int)(2*minval);
        } else {
            return sum;
        }
    }
};