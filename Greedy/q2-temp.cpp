#include<bits/stdc++.h>
using namespace std;

struct Job {
    int profit;
    int dead;
    int id;
};

bool sortFun (Job a, Job b) {
    if(a.dead<b.dead) {
        return true;
    } else if(a.dead>b.dead) {
        return false;
    } else {
        if(a.profit>b.profit)
            return true;
        else return false;
    }
}

pair<int,int> JobScheduling(Job arr[], int n) 
{ 
    int count=0, ans=0, 
    sort(arr, arr+n, sortFun);
    for(int i=0; i<n; i++) {
        count++;
        ans += arr[i].profit;
        while(i<n-1 && arr[i].dead==arr[i+1].dead) {
            i++;
        }
    }
    return make_pair(count, ans);
}