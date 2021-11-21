// My approach : find lca then find the distance from lca to a and b
// (same as on gfg)
Node* findlca(Node* root ,int n1 ,int n2 )
{
    if (!root) return root;
    
    if (root->data == n1 || root->data == n2) return root;
    
    Node* left = findlca (root->left, n1, n2);
    Node* right = findlca (root->right, n1, n2);
    
    if (left && right) return root;
    if (left) return left;
    return right;
}

int dist (Node* root, int a, int depth = 0) {
    if (!root) return INT_MAX;
    
    if (root->data == a) return depth;
    
    return min (dist (root->left, a, depth+1), dist (root->right, a, depth+1)); 
}

int findDist(Node* root, int a, int b) {
    Node* lca = findlca (root, a, b);
    return dist (lca, a) + dist (lca, b); 
}