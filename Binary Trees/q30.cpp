// referred gfg editorial: 
class Solution{
  public:
    int res=0;
    void printKPathUtil(Node* root, vector<int>& path, int k)
    {
        if (!root) return;
      
        path.push_back(root->data);

        printKPathUtil(root->left, path, k);
        printKPathUtil(root->right, path, k);
      
        int f = 0;
        for (int j = path.size() - 1; j >= 0; j--) {
            f += path[j];
      
            if (f == k) res++;
        }
        path.pop_back();
    }

    int sumK(Node *root,int k)
    {
        vector<int> path;
        printKPathUtil(root, path, k);
        return res;
    }
};