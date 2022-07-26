// LISS(X) = MAX { (1 + sum of LISS for all grandchildren of X),
//                      (sum of LISS for all children of X) }

// then memoize by creating a hashmap for node* and int

unordered_map<Node*, int> memo;

int util (Node* root) {
    if (root == NULL) return 0;
 
    if (memo.find(root) != memo.end()) return memo[root];
 
    int liss_excl = util(root->left) + util(root->right);
 
    int liss_incl = 1;
    if (root->left) liss_incl += util(root->left->left) + util(root->left->right);
    if (root->right) liss_incl += util(root->right->left) + util(root->right->right);
 
    memo[root] = max(liss_incl, liss_excl);
 
    return memo[root];
}

int LISS(Node *root)
{
    memo.clear();
    return util (root);
}