// Sort the array
// Fix first two elements then find the rest two by two pointer algo
vector<vector<int> > fourSum(vector<int> &arr, int k) {

    sort (arr.begin(), arr.end());
    
    vector<vector<int>> res;
    int n = arr.size();
    
    for (int i=0; i<n; i++) {
        
        if (i!=0 && arr[i]==arr[i-1]) continue;
        
        for (int j=i+1; j<n; j++) {
            
            if (j!=i+1 && arr[j]==arr[j-1]) continue;
            
            int low = j+1, high = n-1;
            int target = k-arr[i]-arr[j];
            while (low<high) {
            
                if (arr[low] + arr[high] == target) {
                    
                    res.push_back({arr[i], arr[j], arr[low], arr[high]});
                    low++, high--;
                    
                    while (low<high && arr[low]==arr[low-1]) low++;
                    while (high>low && arr[low] == arr[high+1]) high--;
                } 
                else if (arr[low] + arr[high] > target) high--;
                else low++;
            }
        }
    }
    return res;
}