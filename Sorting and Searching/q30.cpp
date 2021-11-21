#define lld long long int

class Solution 
{
    public:
    
    bool feasible (int arr[], int size, int no_of_stud, lld limit) {
        lld cur = 0;
        int stud_req=0;
        for (int i=0; i<size; i++) {
            if (cur+(lld)arr[i] <= limit) {
                cur += (lld)arr[i];
            }else {
                stud_req ++;
                cur = arr[i];
            }
        }
        return stud_req+1 <= no_of_stud;
    }
    
    int findPages(int arr[], int n, int m) 
    {
        lld high = 0, low = 0;
        for (int i=0; i<n; i++) {
            high += (lld) arr[i];
            low = max ((int)low, arr[i]);
        }
        while (low < high) {
            lld mid = (low + high) >> 1;
            if (feasible (arr, n, m, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};