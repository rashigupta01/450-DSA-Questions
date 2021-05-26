// just sort so the larger value of i multiplied by larger value.

#define ll long long int
#define M 1000000007

class Solution{
    public:
    int Maximize(int a[],int n)
    {
        sort (a, a+n);
        ll res = 0;
        for (int i=0; i<n; i++) res = (res +  (((ll)a[i]) * ((ll)i))%M) % M;
        return res;
    }
};