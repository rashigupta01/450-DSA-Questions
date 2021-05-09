// Approach 1 : time complexity - O(r*c*r)
class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        int ptr[r] = {0};
        int median;
        for (int i=0; i<=(r*c)/2; i++) {
            int mnpos = -1;
            for (int j=0; j<r; j++) {
                if (ptr[j]<c) {
                    if (mnpos==-1 || matrix[j][ptr[j]]<matrix[mnpos][ptr[mnpos]]) {
                        mnpos = j;
                    }
                }
            }
            median = matrix[mnpos][ptr[mnpos]];
            ptr[mnpos]++;
        }
        return median;
    }
};

// Approach 2 : https://www.geeksforgeeks.org/find-median-row-wise-sorted-matrix/
// Apply binary search with low as min element and high as max element 
// mid is median if there are exactly r*c/2 elements smaller than mid
int binaryMedian(int m[][MAX], int r ,int c)
{
    int min = INT_MAX, max = INT_MIN;
    for (int i=0; i<r; i++)
    {
        // Finding the minimum element
        if (m[i][0] < min)
            min = m[i][0];
  
        // Finding the maximum element
        if (m[i][c-1] > max)
            max = m[i][c-1];
    }
  
    int desired = (r * c + 1) / 2;
    while (min < max)
    {
        int mid = min + (max - min) / 2;
        int place = 0;
  
        // Find count of elements smaller than mid
        for (int i = 0; i < r; ++i)
            place += upper_bound(m[i], m[i]+c, mid) - m[i];
        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}