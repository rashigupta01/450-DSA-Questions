// Approach : 
// do inorder traversal of the given bst
// construct balenced bst using it, reccursively

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* left, *right;

    Node (int val) {
        data = val;
        left = right = NULL;
    }
};

void inorder (Node* root, vector<int> &traversal) {
	if (root==NULL)	return;

	inorder (root->left, traversal);
	traversal.push_back(root->data);
	inorder (root->right, traversal);
}

Node* util (vector<int> traversal, int low, int high) {
    if (low>high) return NULL;
    // if (low==high) return new Node (traversal[low]);

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

void preOrder(Node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

// Driver program
int main()
{
	/* Constructed skewed binary tree is
				10
			/
			8
			/
			7
		/
		6
		/
		5 */

	Node* root = new Node (10);
	root->left = new Node (8);
	root->left->left = new Node (7);
	root->left->left->left = new Node (6);
	root->left->left->left->left = new Node (5);

	root = construct_balenced_bst(root);

	printf("Preorder traversal of balanced BST is : \n");
	preOrder(root);

	return 0;
}
