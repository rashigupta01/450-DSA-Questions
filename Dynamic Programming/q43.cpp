string longestPalindrome(string A){
    int n = A.size();
    int res = 0;
    int ri, rj;
    for (int i=0; i<n; i++) {
        int len = 0;
        while (i-len >=0 && i+len<n) {
            if (A[i-len] != A[i+len]) break;
            len++;
        }
        if (res < 1 + 2 * (len-1)) {
            res = 1 + 2 * (len-1);
            ri = i-len+1;
            rj = i+len-1;
        }
        len = 0;
        while (i-len>=0 && i+len+1<n) {
            if (A[i-len] != A[i+len+1]) break;
            len++;
        }
        if (res < 2 * (len)) {
            res = 2 * (len);
            ri = i-len+1;
            rj = i+len;
        }
        
    }
    return A.substr(ri, rj-ri+1); 
}

// Method 2: Dynamic Programming. 
/*
To calculate table[i][j], check the value of table[i+1][j-1], if the value is true and str[i] is same as str[j], 
then we make table[i][j] true. Otherwise, the value of table[i][j] is made false.
*/