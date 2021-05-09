// ? Yet to submit............ perfect from my side


// Map or a counter array could be maintained to store the frequency of each element

// Best approach using xor
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // xor of 1..N
        int net_xor = 0;
        for (int i=1; i<=n; i++) net_xor ^= i;
        
        int arr_xor = 0;
        for (int i=0; i<=n-1; i++) net_xor ^= arr[i];
        
        int xor_pair = net_xor ^ arr_xor;
        int mask = xor_pair & (-xor_pair);
        
        int A, B;
        for (int i=0; i<n; i++) {
            if (arr[i]&mask) {
                A ^= arr[i];
            } else {
                B ^= arr[i];
            }
            
            if ((i+1)&mask) {
                A ^= (i+1);
            } else {
                B ^= (i+1);
            }
        }
        
        for (int i=0; i<n; i++) {
            if (arr[i] == A) {
                swap (A, B);
            }
        }
        
        int ans[] = {B, A};
        return ans;
    }
};
