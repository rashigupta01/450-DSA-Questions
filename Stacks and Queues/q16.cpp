// sort and one by one merge with top in result
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        int i = 1;
        int start = intervals[0][0], end = intervals[0][1];
        while(i<intervals.size()) {
            if(intervals[i][0]<=end) {
                end = max(end, intervals[i][1]);
            }else {
                result.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            i++;
        }
        result.push_back({start, end});
        return result;
    }
};