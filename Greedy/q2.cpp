// Greedy approach : select the jobs in dec order of profit and execute it if there is a free slot

// ----------------- My approach - O(n^2) approach -----------------------
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

// ------------------------ O(n) approach on gfg------------------
//* https://www.geeksforgeeks.org/job-sequencing-using-disjoint-set-union/
// The idea is to create all the adjacent booked time slots into one set.