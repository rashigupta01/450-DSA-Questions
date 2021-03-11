
// Approach: Sort the interval with start value. Keep meging if start(i) < end and update end
bool comp(vector<int> a, vector<int> b) {
        if(a[0]<b[0]) {
            return true;
        } else if (a[0]>b[0]) {
            return false;
        } else {
            if(a[1]<b[1]) {
                return true;
            } else {
                return false;
            }
        }
    }

class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), comp);
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