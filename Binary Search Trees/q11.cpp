// Approach 1: insert one tree nodes into another

// Approach 2: find inorder traversal of both the trees then use merge function of merge sort
// then convert it into a bst
// If we have to merge without creating new nodes, node pointers can be stored in inorder vectors
// code similar to done in q10

void inorder (Node *root, vector<int> &v) {
    if (!root) return;
    inorder (root->left, v);
    v.push_back(root->data);
    inorder (root->right, v);
}

vector<int> merge (vector<int> v1, vector<int> v2) {
    vector<int> res;
    int i=0, j=0;
    while (i<v1.size() && j<v2.size()) {
        if (v1[i] < v2[j]) {
            res.push_back(v1[i]);
            i++;
        } else {
            res.push_back(v2[j]);
            j++;
        }
    }
    while (i<v1.size()) {
        res.push_back(v1[i]);
        i++;
    }
    while (j<v2.size()) {
        res.push_back(v2[j]);
        j++;
    }
    return res;
}

//Function to return a list of integers denoting the node 
//values of both the BST in a sorted order.
vector<int> merge(Node *root1, Node *root2)
{
    vector<int> v1;
    inorder (root1, v1);
    vector<int> v2;
    inorder (root2, v2);
    
    return merge (v1, v2);
}