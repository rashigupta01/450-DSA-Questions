// root -> left -> right ---->> reverse of (right -> left -> root)

// approach is similar to iterative preorder traversal (q7)
// instead of first pushing right child and then left child
// push left first then right child and while visiting (or popping) a node push it to a temp stack
// final order would pe the reverse of temp