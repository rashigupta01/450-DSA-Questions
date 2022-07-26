// Approach 1: Use two loops and check every pair possible

// Approach 2: Sort the array, for each element, x,  binary search for x+diff

// Approach 3: Sort the array, use two pointer. Initialize the two pointer at index 0 and 1, then increment i and j
// according their difference

// Approach 4: Hash all the elements and check if x+diff exists or not in the map
bool findPair(int arr[], int size, int n){
    unordered_set <int> m;
    for (int i=0; i<size; i++) {
        if (m.find(arr[i]-n) != m.end()) return true;
        if (m.find(arr[i]+n) != m.end()) return true;
        m.insert(arr[i]);
    }
    return false;
}