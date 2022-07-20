// O(n^2) approach:
// find the first greater element that the root... all the elements after this should be more that root
// recurse for both the subarray


// STACK approach: good approach
// Refer editorial: https://www.geeksforgeeks.org/check-if-a-given-array-can-represent-preorder-traversal-of-binary-search-tree/


// my approach (given on gfg as well) (giving seg fault on 1-2 tc)
void util (int arr[], int &pos, int N, int min, int max) {
    if (pos>=N) return;
    if (arr[pos] > max || arr[pos] < min) return;
    
    int root = arr[pos];
    pos++;
    util (arr, pos, N, min, root);
    util (arr, pos, N, root, max);
}

int canRepresentBST(int arr[], int N) {
    int pos = 0;
    util (arr, pos, N, INT_MIN, INT_MAX);
    return pos==N;
}