// O(n^2) approach
// create first element as root then reccurse for left and right, for that find the first greater element than root

// O(nlogn) approach
// preorder is given
// inorder will be sorted preorder 
// now bst can be created simply as normal bt using pre and inorder 

// O(n) approach
// keep a range {min, max} and srink it as we move o the right or left of root, if the current element satisfy the condition create 
// node and reccurse otherwise return null