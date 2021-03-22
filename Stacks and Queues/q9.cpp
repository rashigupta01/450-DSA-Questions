// My approach: 
vector<long long> nextLargerElement(vector<long long> arr, int n){
    stack <long long> s;
    vector<long long > res(n);
    for (int i=n-1; i>=0; i--) {
        while (!s.empty() && s.top()<arr[i]) {
            s.pop();
        }
        res[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    return res;
}