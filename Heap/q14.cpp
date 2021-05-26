long long minCost(long long a[], long long n) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(long long i=0; i<n; i++) {
        pq.push(a[i]);
    }
    long long cost = 0;
    while(pq.size() > 1) {
        long long r1 = pq.top();
        pq.pop();
        long long r2 = pq.top();
        pq.pop();
        cost += r1+r2;
        pq.push(r1+r2);
    }
    return cost;
}