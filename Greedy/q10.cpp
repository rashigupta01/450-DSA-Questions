vector<int> candyStore(int candies[], int N, int K)
{
    sort (candies, candies+N);
    int mn = 0, mx = 0, candy =0;
    for (int i=0; i<N && candy <N; i++) {
        mn += candies[i];
        candy += K+1;
    }
    candy = 0;
    for (int i=N-1; i>=0 && candy<N; i--) {
        mx += candies[i];
        candy += K+1;
    }
    return {mn, mx};
}