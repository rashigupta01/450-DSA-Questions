pair<int,int> findSmallestRange(int arr[][N], int n, int k)
{
    int final_mx=INT_MIN, final_mn=INT_MAX;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (int i=0; i<k; i++) {
        pq.push({arr[i][0], {i, 0}});
        final_mx = max (final_mx, arr[i][0]);
        final_mn = min (final_mn, arr[i][0]);
    }
    int mx_cur = final_mx, mn_cur = final_mn;
    while (pq.size()==k) {
        auto ele = pq.top();
        pq.pop();
        if (ele.second.second == n-1) break;
        
        int next_ele = arr[ele.second.first][ele.second.second+1];
        pq.push({next_ele, {ele.second.first, ele.second.second+1}});
        if (pq.top().first > mn_cur) {
            mn_cur = pq.top().first;
        }
        if (next_ele > mx_cur) {
            mx_cur = next_ele;
        }
        
        if (final_mx-final_mn > mx_cur-mn_cur) {
            final_mx = mx_cur;
            final_mn = mn_cur;
        }
    }
    return {final_mn, final_mx};
}