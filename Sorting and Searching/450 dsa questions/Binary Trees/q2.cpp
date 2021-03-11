// Approach 1: In the normal level order traversal, insert the values right to left, and finally reverse the array.

// Approach 2: for vector of levels, once a vector for current level is formed, insert it to the front of resultant vector.
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    if(root == NULL) return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int levcount = q.size();
        vector<int> curqueue;
        for(int i=0; i<levcount; i++) {
            TreeNode* temp = q.front();
            q.pop();
            curqueue.push_back(temp->val);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        res.insert(res.begin(), curqueue);
    }
    return res;
}