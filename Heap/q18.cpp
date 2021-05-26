// Approach: sort the array, now turn wise place the digits in the numbers and return their sum
// no use of heaps
string add (string a, string b) {
    string c;
    int p1 = a.size()-1, p2 = b.size()-1;
    int carry=0, sum;
    
    while (p1>=0 || p2>=0) {
        sum = (p1>=0 ? a[p1]-'0' : 0) + (p2>=0? b[p2]-'0' : 0) + carry;
        carry = sum/10;
        c.push_back(sum%10 + '0');
        p1--, p2--;
    }
    if (carry) {
        c.push_back(carry + '0');
    }

    while (c[c.size()-1] == '0') c.pop_back();
    reverse (c.begin(), c.end());
    return c.empty() ? "0" : c;
}
string solve(int arr[], int n) {
    
    sort (arr, arr+n);
    
    vector<string> nums(2); 
    bool turn = false;
    for (int i=0; i<n; i++) {
        nums[turn].push_back(arr[i] + '0');
        turn = !turn;
    }
    return add(nums[0], nums[1]);
}