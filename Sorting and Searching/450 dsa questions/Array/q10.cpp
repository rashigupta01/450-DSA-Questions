
// Approach 1 (Greedy): At the currect position chose the best position where he must jump. (TC-O(n^2))
int jump(vector<int>& a) {
    int n = a.size();
    int i=0, jumps = 0, maxVal, j, jumpto; 
    while(i<n-1) {
        if(i+a[i]>=n-1) {
            jumps++;
            return jumps;
        }
        maxVal = 0;
        for(j=1; j<=a[i] && i+j<n; j++) {
                
            if(maxVal < a[i+j] + j) {
            	maxVal = a[i+j] + j;
            	jumpto = j;
        	}
        }
        if(maxVal == 0)
            return -1;
        i+=jumpto;
        jumps++;
    }
    return jumps;
}

// Approach 2: (refer: https://www.geeksforgeeks.org/minimum-number-jumps-reach-endset-2on-solution/) 
// For visual understanding refer: https://www.youtube.com/watch?v=vBdo7wtwlXs
// (TC-O(n))