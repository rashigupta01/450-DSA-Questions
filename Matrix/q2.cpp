// Approach 1 : consider the matrix as a 1 D straing array
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size(), n;
        if(m) n = matrix[0].size();
        else n = 0;

        int low = 0, high = m*n-1, i, j, mid;
        while(low<=high) {
            mid = low + (high-low)/2;
            i=mid/n;
            j=mid-i*n;
            
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] > target)
                high = mid-1;
            else 
                low = mid+1;            
        }
        return false;
    }
};

// Approach 2 : Do a lower bound binary search in first value of each rows then binary search in that perticular row