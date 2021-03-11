// https://www.geeksforgeeks.org/zigzag-tree-traversal/

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(root == NULL) return res;
    
    queue<TreeNode*> q;
    q.push(root);
    bool rev = false;
    
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
        if (rev) {
            reverse(curqueue.begin(), curqueue.end());
        }
        rev = !rev;
        res.push_back(curqueue);
    }
    return res;
}

// Approach 2:
// use two stacks and a boolean to check the direction. use one stack for printing from left to right and other stack for printing from right to left