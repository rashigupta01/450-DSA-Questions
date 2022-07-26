// DP on trees: cosider root then do not consider root
class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    
    unordered_map<Node*, int> m;
    
    int util (Node *root) {
        if (!root) return 0;
        if (m[root] != 0) return m[root];
        
        int sum1 = util (root->left) + util (root->right);
        int sum2 = root->data;
        if (root->left) sum2 += util (root->left->right) + util (root->left->left);
        if (root->right) sum2 += util (root->right->right) + util (root->right->left);
        
        return m[root] = max (sum1, sum2);
    }
    
    int getMaxSum(Node *root) 
    {
        return util (root);
    }
};

// another approach: no dp, bottom up
// return pair of vals: first of the pair indicates maximum sum when the data of a node is included and the 
// second indicates maximum sum when the data of a particular node is not included. 