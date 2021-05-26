// Simple backtracking question

// visit the current element, reccurse for all four directions. if invalid element return -1. else return max of all
// four reccursions + 1. backtrack by unvisiting current element
// keeping a visited matrix can be avoided by updating the matrix with 0 (making it a hurdle)