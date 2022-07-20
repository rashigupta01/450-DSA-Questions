// start from right to left and keep inserting it into a bst. also keep storing the inorder successor while inserting
// worst case time complexity:: O(n^2) 
class Node {
    public:
        int data;
        Node* left, *right;
        Node(int key) {
            data = key;
            left = right = NULL;
        }
};

Node* insert (Node *root, int key, int &lge) {
    
    if (!root) return new Node(key);
    
    if (key < root->data) {
        lge = root->data;
        root->left = insert(root->left, key, lge);
    } else {
        root->right = insert(root->right, key, lge);
    }
    
    return root;
}

class Solution{
    public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        Node* root = NULL;
        
        vector<int> res(n, -1);
        for (int i=n-1; i>=0; i--) {
            root = insert (root, arr[i], res[i]);
        }
        return res;
    }
};

// Efficient O(nlogn) stack NGE approach: 
/*
First, we take an array of pairs namely temp, and store each element and its index in this array,i.e. temp[i] will be storing {arr[i],i}.
Sort the array according to the array elements.
Now get the next greater index for each and every index of the temp array in an array namely index by using Next Greater Element using stack.
Now index[i] stores the index of the next least greater element of the element temp[i].first and if index[i] is -1, then it means that there is no least greater element of the element temp[i].second at its right side.
Now take a result array where result[i] will be equal to a[indexes[temp[i].second]] if index[i] is not -1 otherwise result[i] will be equal to -1.
*/