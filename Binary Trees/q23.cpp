
// My approach
// same as of editorial
class Solution{
  public:
    /*You are required to complete this method*/
    int depth = -1;
    bool check(Node *root, int curdepth=0)
    {
        if (root==NULL) return true;
        if (!root->left && !root->right) {
            if (depth==-1) {
                depth = curdepth;
                return true;
            } else {
                return depth == curdepth;
            }
        }
        
        return check(root->left, curdepth+1) && check (root->right, curdepth+1);
    }
};