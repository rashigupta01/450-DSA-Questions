// https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

// MY APPROACH:
// i used a vector where a new element is pushed back only if it is less than the last element else the last element was popped
// this was at any instant the vector will store the elemets in descending order having the first element as the largest
// now if an element is no longer the part of the window and is equal to the first element the first element was erased
vector <int> max_of_subarrays(int *arr, int n, int k){
    vector<int> st;
    vector<int> result;
    for (int i=0; i<k; i++) {
        while (!st.empty() && st[st.size()-1] < arr[i]) {
            st.pop_back();
        }
        st.push_back(arr[i]);
    }
    
    for (int i=k; i<=n; i++) {
        result.push_back(st[0]);
        if (i==n) return result;
        
        while (!st.empty() && st[st.size()-1] < arr[i]) {
            st.pop_back();
        }
        st.push_back(arr[i]);
        
        if (arr[i-k] == st[0]) {
            st.erase(st.begin());
        }
    }
    return result;
}
// NOTE: This could be improved by using a dequeue (that would be the most efficient approach)