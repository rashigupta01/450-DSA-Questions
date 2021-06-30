// O(n^2) approach
int result = 0;
int largestBstUtil (Node *root, int low, int high) {
    
    if (root==NULL) {
        return 0;
    }
    if (root->data>low && root->data<high) {
        int left = largestBstUtil (root->left, low, root->data);
        int right = largestBstUtil (root->right, root->data, high);
        
        if (left!=-1 && right!=-1) {
            result = max (result, left+right+1);
            return left+right+1;
        }
    }
    
    largestBstUtil (root->left, INT_MIN, INT_MAX);
    largestBstUtil (root->right, INT_MIN, INT_MAX);
    return -1;
}

int largestBst (Node* root) {
    result = 0;
    largestBstUtil (root, INT_MIN, INT_MAX);
    return result;
}

// O(n) approach
int result = 0;
struct s {
    bool isBst;
    int size, min, max;
    s (bool a, int b, int c, int d) {
        isBst = a;
        size = b;
        min = c;
        max = d;
    }
};
struct s largestBstUtil (Node *root) {
    
    if (root==NULL) {
        s temp (true, 0, INT_MAX, INT_MIN);
        return temp;
    }
    s left = largestBstUtil (root->left);
    s right = largestBstUtil (root->right);
    
    s current (false, left.size + right.size + 1, min(root->data, left.min), max (root->data, right.max));
    if (root->data > left.max && root->data < right.min) {
        if (left.isBst && right.isBst) {
            current.isBst = true;
            result = max (result, current.size);
        }
    }
    return current;
}
int largestBst (Node* root) {
    result = 0;
    largestBstUtil (root);
    return result;
}