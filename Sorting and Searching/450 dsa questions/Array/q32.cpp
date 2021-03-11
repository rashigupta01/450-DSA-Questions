// Approach 1: sort the array. (TC-O(nlogn) SC-O(1))

// Approach 2: take three temp arrays, one to store values less than a, one for values in range [a, b] and one for greater than b.
// (TC-O(n) SC-O(n))

// Approach 3: Dutch National Flag Algorithm. (TC-O(n) SC-O(1))
class Solution{   
public:
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        int low=-1, mid=0, high=array.size();
        while(mid<high) {
            if(array[mid]<=b && array[mid]>=a) {
                mid++;
            } else if (array[mid]<a) {
                low++;
                swap(array[low], array[mid]);
                mid++;
            } else {
                high--;
                swap(array[high], array[mid]);
            }
        }
    }
};