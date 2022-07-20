// find the inorder traversal and store it in an array then return the middle element   

// count number of nodes and return the n/2 the element in inorder traversal (do not maintain the array)
int count (Node* root) {
    if (root==NULL) return 0;
    
    return 1 + count(root->left) + count(root->right);
}
int valatposition (Node* root, int &c, int pos) {
    if (!root) return-1;
    
    int l = valatposition (root->left, c, pos);
    if (l!=-1) return l;
    
    c++;
    if (c==pos) return root->data;
    
    int r = valatposition (root->right, c, pos);
    if (r!=-1) return r;
    
    return -1;
}
float findMedian(struct Node *root)
{
    int n = count (root);
    int c=0;
    if (n%2) {
        return valatposition (root, c, (n+1)/2);
    } else {
        int a = valatposition (root, c, n/2);
        c=0;
        int b = valatposition (root, c, n/2 + 1);
        return ((float) (a+b))/2; 
    }
}

// To avoid space of recursion stack, morris traversal can be used.