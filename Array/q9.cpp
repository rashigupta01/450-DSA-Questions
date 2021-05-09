// ! Logic same as on gfg, failing on some testcases
class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        int cur_max, cur_min, initial_diff;
        sort(arr, arr + n);
        initial_diff = arr[n-1] - arr[0];
        
        arr[0] += k;
        arr[n-1] -= k;
        
        if (arr[n-1]<0) return initial_diff;
        
        cur_max = arr[0] >= arr[n-1] ? arr[0] : arr[n-1];
        cur_min = arr[0] >= arr[n-1] ? arr[n-1] : arr[0];
        
        for(int i=1; i<n-1; i++) {
            if(arr[i]<=k) {
                arr[i] += k;
                if(arr[i] < cur_min) cur_min = arr[i];
                if(arr[i] > cur_max) cur_max = arr[i];
            }
            else {
                
                if (arr[i] + k <= cur_max && arr[i] + k >= cur_min) continue;
                else if (arr[i] - k <= cur_max && arr[i] - k >= cur_min) continue;
                
                if (arr[i] + k - cur_max > cur_min - arr[i] + k) cur_min = arr[i]-k;
                else cur_max = arr[i]+k;
            }
        }
        return min (initial_diff, cur_max - cur_min);
    }
};