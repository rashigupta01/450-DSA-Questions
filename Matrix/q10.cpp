/*
The idea is to use maps. We initially insert all elements of the first row in an map. For every other element in remaining rows, 
we check if it is present in the map. If it is present in the map and is not duplicated in current row, we increment count of the 
element in map by 1, else we ignore the element. If the currently traversed row is the last row, we print the element if it has
appeared m-1 times before. 

https://www.geeksforgeeks.org/common-elements-in-all-rows-of-a-given-matrix/
*/

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