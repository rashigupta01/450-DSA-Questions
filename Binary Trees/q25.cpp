// My approach, took hint from  comment section
// similar to given in editorial
class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        unordered_map<int, stack<int>> m1;
        for (int i = 0; i<2*e; i+=2) {
            m1[A[i]].push(A[i+1]);
        }
        for (int i=0; i<2*e; i+=2) {
            if (m1[B[i]].top()!=B[i+1]) return false;
            m1[B[i]].pop();
        }
        return true;
    }
};