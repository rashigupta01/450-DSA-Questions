// My approach: can't validate due to nol= link for proactice
bool check (vector<int> input, vector<int> output) {
    stack<int> s;
    int n = input.size();
    int p1=0, p2=0;
    while (p2<n) {
        if (s.empty() || s.top()!=output[p2]) {
            if (p1==n) return false;
            s.push(input[p1++]);
        } else {
            p2++;
            s.pop();
        }
    }
    return true;
}