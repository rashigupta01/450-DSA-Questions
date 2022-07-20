// Not using the fact the bt is bst.
// Approach: hash the elements in one bst.
unordered_set <int> s;
int res = 0;
void inorder1 (Node* root) {
    if (!root) return;
    inorder1(root->left);
    s.insert(root->data);
    inorder1(root->right);
}

void inorder2 (Node* root, int x) {
    if (!root) return;
    inorder2(root->left, x);
    if (s.find(x-root->data) != s.end()) res++;
    inorder2(root->right, x);
}
int countPairs(Node* root1, Node* root2, int x)
{
    s.clear();
    res = 0;
    inorder1(root1);
    inorder2(root2, x);
    return res;
}

// do iterative inorder (reverse inorder for second bst) for both bst iteratively, 
// Sum up the corresponding node’s value from both the BSTs at a particular instance of traversals.
// If sum == x, then increment count. If x > sum, then move to the inorder successor of the current node of BST 1,
// else move to the inorder predecessor of the current node of BST 2. 