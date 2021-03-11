// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

/*

1) Sort the activities according to their finishing time 
2) Select the first activity from the sorted array and print it. 
3) Do following for remaining activities in the sorted array. 
    If the start time of this activity is greater than the finish time of previously selected activity then select this activity and print it.

*/


#include<bits/stdc++.h>
using namespace std;

bool sortFun (pair<int, int> a, pair<int, int> b) {
    return a.second<b.second;
}

int maxMeetings(int start[], int end[], int n) {
    vector<pair<int, int>> v;
    for(int i=0; i<n; i++) {
        v.push_back({start[i], end[i]});
    }
    sort(v.begin(), v.end(), sortFun);
    int count=1;
    int prevEnd = v[0].second;
    for(int i=1; i<n; i++) {
        if(v[i].first>prevEnd) {
            prevEnd=v[i].second;
            count++;
        }
    }
    return count;
}