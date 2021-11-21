// Approach: store the path from root to n1 and n2 then return the last common node in the path
bool findPath (Node* root, int key, vector<Node*> &path) {
    if(root==NULL) return false;
    
    if(root->data == key) {
        path.push_back(root);
        return true;
    }
    if(findPath(root->left, key, path)) {
        path.push_back(root);
        return true;
    }
    if(findPath(root->right, key, path)) {
        path.push_back(root);
        return true;
    }
    return false;
}
Node* lca(Node* root, int p, int q) {
    vector<Node*> p1, p2;
    if(!findPath(root, p, p1) || !findPath(root, q, p2)) return NULL;
    
    int pt1 = p1.size()-1, pt2 = p2.size()-1;
    Node* temp;
    while (1) {
        if(p1[pt1] != p2[pt2]) break;
        temp = p1[pt1];
        pt1--; pt2--;
    }
    return temp;
}

// Best approach! Refered Tushar Roy yt video
class Solution
{
    public:
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        if (!root) return root;
        
        if (root->data == n1 || root->data == n2) return root;
        
        Node* left = lca (root->left, n1, n2);
        Node* right = lca (root->right, n1, n2);
        
        if (left && right) return root;
        if (left) return left;
        return right;
    }
};