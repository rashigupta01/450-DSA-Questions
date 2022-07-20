// Approach 1:
// Create a dummy node.
// Create a variable called ‘prev’ and make it point to the dummy node.
// Perform in-order traversal and at each step. 
//  Set prev -> right = curr
//  Set prev -> left = NULL
//  Set prev = curr


// Approach 2:
// flatten left
// flatten right
// last node of left -> right = root;
// root->right = flatten right