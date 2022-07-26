
class Solution
{
public:
    pair<int, int> res;     // sum, depth 
    
    void util (Node* root, int sum, int depth) {
        
        if (!root) return;
        
        sum += root->data;
        if (!root->left && !root->right) {
            if (depth > res.second) {
                res = {sum, depth};
            } else if (depth == res.second) {
                res.first = max (sum, res.first);
            }
            return;
        }
        util(root->left, sum, depth+1);
        util(root->right, sum, depth+1);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        res = {INT_MIN, 0};
        util (root, 0, 0);
        return res.first;
    }
};