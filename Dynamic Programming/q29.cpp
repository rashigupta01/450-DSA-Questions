
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


// DP approaches : (TC-O(n^2)) https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/


// Approach 2: (refer: https://www.geeksforgeeks.org/minimum-number-jumps-reach-endset-2on-solution/) 
// For visual understanding refer: https://www.youtube.com/watch?v=vBdo7wtwlXs
// (TC-O(n))
class Solution{
  public:
    int minJumps(int arr[], int n){
        int curladder = 0;
        int jumps = 0;
        int i=0; 
        int reach = 0;
        while (i<n) {
            bool check = true;
            for (; i<n && i<=curladder; i++) {
                check = false;
                reach = max (reach, arr[i] + i);
            }
            if (check) return -1;
            curladder = reach;
            jumps++;
        }
        return jumps-1;
    }
};