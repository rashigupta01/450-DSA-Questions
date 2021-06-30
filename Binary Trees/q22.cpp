
// Alternate tricky point: sum of left subtree would be twice of data in left child 

// My approach
class Solution
{
    public:
    bool util (Node* root, int &sum) {
        if (root==NULL) return true;
        
        int sumleft = 0, sumright=0;
        bool checkleft = util (root->left, sumleft);
        bool checkright = util (root->right, sumright);
        
        sum = sumleft + sumright + root->data;
        
        return (sumleft+sumright == root->data); 
    }
    bool isSumTree(Node* root)
    {
        int sum;
        return util(root, sum); 
    }
};