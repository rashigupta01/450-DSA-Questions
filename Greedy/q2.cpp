#include<bits/stdc++.h>
using namespace std;

struct Job {
    int profit;
    int dead;
    int id;
};


bool sortFun (Job a, Job b) {
    return a.profit>b.profit;
}

pair<int,int> JobScheduling(Job arr[], int n) 
{ 
    unordered_map<int, bool> check;
    sort(arr, arr+n, sortFun);
    int count=0, ans=0;
    for(int i=0; i<n; i++) {
        int j=arr[i].dead - 1;
        while(j>=0) {
            if(!check[j]) {
                check[j]=true;
                count++;
                ans+=arr[i].profit;
                break;
            }
            j--;
        }
    }
    return make_pair(count, ans);
}