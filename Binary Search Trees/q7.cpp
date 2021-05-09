// simply using the fact that for lca shorter node will be in its left subtree and greater node will be in its right subtree
// my code
Node* LCA(Node *root, int n1, int n2)
{
    if (!root) return NULL;
    
    if (root->data == n1 || root->data == n2) return root;
    
    if (root->data < n1) {
        if (root->data < n2) return LCA (root->right, n1, n2);
        else return root;
    } else {
        if (root->data > n2) return LCA (root->left, n1, n2);
        else return root;
    }
}

// Simple and concice code on gfg :)
node *lca(node* root, int n1, int n2) { 
    if (root == NULL) return NULL; 
    if (root->data > n1 && root->data > n2) return lca(root->left, n1, n2); 
    if (root->data < n1 && root->data < n2) return lca(root->right, n1, n2); 
    return root; 
}