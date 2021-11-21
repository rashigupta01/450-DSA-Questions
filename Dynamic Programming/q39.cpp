// LISS(X) = MAX { (1 + sum of LISS for all grandchildren of X),
//                      (sum of LISS for all children of X) }

// then memoize by creating a hashmap for node* and int