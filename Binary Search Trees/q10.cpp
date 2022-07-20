// Approach : 
// do inorder traversal of the given bst
// construct balenced bst using it, reccursively

void inorder (Node* root, vector<int> &traversal) {
	if (root==NULL)	return;

	inorder (root->left, traversal);
	traversal.push_back(root->data);
	inorder (root->right, traversal);
}

Node* util (vector<int> traversal, int low, int high) {
    if (low>high) return NULL;

    int mid = (low+high)/2;
    Node* root = new Node (traversal[mid]);
    root->left = util (traversal, low, mid-1);
    root->right = util (traversal, mid+1, high);
    return root;
}

Node* construct_balenced_bst (Node* root) {

	vector<int> traversal;
	inorder (root, traversal);

	int n = traversal.size();
	return util (traversal, 0, n-1);
}