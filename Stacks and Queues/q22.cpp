// My approach: 
int isStackPermutation(int n, vector<int> &input,vector<int> &output){
    stack<int> s;
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