#include <bits/stdc++.h> 
using namespace std;

// Approach: simply iterate in all three altogether, if it is confirm that a value can't be the intersection just increment the pointer
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector<int> result;
            int p1=0, p2=0, p3=0;
            while (p1<n1 && p2<n2 && p3<n3) {
                if(A[p1] == B[p2] && A[p1] == C[p3]) {
                    result.push_back(A[p1]); 
                    p1++; p2++; p3++;
                    while(p1<n1 && A[p1] == A[p1-1]) p1++;
                } else if (A[p1] > B[p2]) {
                    p2++;
                } else if (A[p1] < B[p2]) {
                    p1++;
                } else {
                    if(A[p1] > C[p3]) {
                        p3++;
                    } else {
                        p1++; p2++;
                    }
                }
            }
            return result;
        }
};