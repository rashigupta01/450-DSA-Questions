// Brute force approach: for every element find its next greater element using a nested loop
// Time complexity : O(n^2)
void brute_force (vector<int> a) {

    for (int i = 0; i < a.size(); i++) {
        int j;
        for (j = i; j < a.size(); j++) {
            if (a[j] > a[i]) {
                cout << a[i] <<"'s NGE is " << a[j] << endl;
                break;
            }
        }
        if (j == a.size()) outfile << a[i] << "'s NGE is " << -1 << endl;
    }
    cout << endl;
}

// Efficient approach using stack: Keep storing elements in descending order in stack. Order of printing will 
// not be same as the order of input.
// Time complexity: O(n)
void efficient (vector<int> a) {

    stack<int> temp;
    
    for (int i = 0; i < a.size(); i++) {
        while (!temp.empty() && a[i] > temp.top()) {
            outfile << temp.top() << "'s NGE is " << a[i] << endl;
            temp.pop();
        }
        temp.push(a[i]);
    }
    while (!temp.empty()) {
        outfile << temp.top() << "'s NGE is " << -1 << endl;
        temp.pop();
    }
    outfile << endl;
}


// My approach: maintaining a stack with increasing order from the back side of array
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
