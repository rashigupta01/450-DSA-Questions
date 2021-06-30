//* IMPORTANT: note j loop is the outer loop and i is the inner loop 
long long int count(long long int n) {

    vector<long long> table(n+1,0);
    table[0] = 1;
    int arr[3]={3,5,10};
    for(int j=0;j<3;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(arr[j]>i) continue;
            table[i] += table[i-arr[j]];
        }
    }
    return table[n];
}