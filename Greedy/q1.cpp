/*
        Algorithm:
1) Sort the activities according to their finishing time 
2) Select the first activity from the sorted array and print it. 
3) Do following for remaining activities in the sorted array. 
    If the start time of this activity is greater than the finish time of previously
    selected activity then select this activity and print it.
*/

int maxMeetings(int start[], int end[], int n) {
    vector<pair<int, int>> v;
    for (int i=0; i<n; i++) {
        v.push_back({end[i], start[i]});
    }
    sort (v.begin(), v.end());
    
    int prev = -1, count = 0;
    for (int i=0; i<n; i++) {
        if (v[i].second > prev) {
            prev = v[i].first;
            count++;
        }
    }
    return count;
}