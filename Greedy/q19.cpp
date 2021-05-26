// ? same as q18

// sort then first insert min then max then next min then next max and so on...
// a[0], a[n-1], a[1], a[n-2], ......
long long int maxSum(int arr[], int n) {
    int a[n];
    sort (arr, arr+n);
    int i=0, j=n-1, pos=0;
    
    while (i<j) {
        a[pos++] = arr[i++];
        a[pos++] = arr[j--];
    }
    if (n&1) {
        a[pos] = arr[i];
    }
    long long sum = abs (a[0]-a[n-1]);
    for (int i=1; i<n; i++) {
        sum += abs(a[i]-a[i-1]);
    }
    return sum;
}

//* on gfg 
// Subtracting a1, a2, a3,....., a(n/2)-1, an/2
// twice and adding a(n/2)+1, a(n/2)+2, a(n/2)+3,.
// ...., an - 1, an twice.
for (int i = 0; i < n/2; i++)
{
    sum -= (2 * arr[i]);
    sum += (2 * arr[n - i - 1]);
}