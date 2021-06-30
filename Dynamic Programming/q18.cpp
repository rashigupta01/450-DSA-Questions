// ! My wrong approach
// Take lcs of first two then lcs with third, ie, return lcs(lcs(a, b), c)
// WHY WRONG? 
// LCS of the first 2 strings may not have anything common with the 3rd string. 
// May be any other common subsequence between the first 2 strings, not necessarily the longest one,
// may lead to the LCS of the 3 strings.


// ? correct approach
// create a 3d matrix and find lcs of 3 strings simultaneously similarly as we find lcs of 2 strings