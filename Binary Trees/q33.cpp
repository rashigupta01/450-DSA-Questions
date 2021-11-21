// My approach : find the path from root to node the return the kth element from node
bool findPath (Node* root, int key, vector<int> &path) {
    if(root==NULL) return false;
    
    if(root->data == key) {
        path.push_back(root->data);
        return true;
    }
    if(findPath(root->left, key, path)) {
        path.push_back(root->data);
        return true;
    }
    if(findPath(root->right, key, path)) {
        path.push_back(root->data);
        return true;
    }
    return false;
}

int kthAncestor(Node *root, int k, int node)
{
    vector<int> path;
    findPath (root, node, path);
    if (path.size()>k) return path[k];
    return -1;
    
}

// other approach could have been doing a dfs and then backracking k times when reached the key