
// Approach 1: Merge function in merge sort. (TC-O(m+n) SC-O(m+n))

// Approach 2: Take 2 pointers one on starting of each array. if a[p1]>b[p2] insert a[p1] at correct position in b. 
// (TC-O(m*n) SC-O(1))
class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	    int pos1=0, pos2=0;
	    while(pos1<n) {
	        if(arr1[pos1]<arr2[pos2]) pos1++;
	        else {
	            int temp = arr1[pos1];
	            arr1[pos1] = arr2[pos2];
	            pos1++;
	            int i=pos2;
	            while(i<m-1 && arr2[i+1]<temp) {
	                arr2[i] = arr2[i+1];
	                i++;
	            }
	            arr2[i]=temp;
	        }
	    }
	}
};

/	/ Approach 3:
void merge(long long arr1[], long long arr2[], int n, int m) 
{ 
	int i = 0, j = 0, k = n - 1;
	
	// Until i less than equal to k
	// or j is less than m
	while (i <= k && j < m) {
		if (arr1[i] < arr2[j])
			i++;
		else {
			swap(arr2[j++], arr1[k--]);
		}
	}
	
	// Sort first array
	sort(arr1, arr1 + n);
	
	// Sort second array
	sort(arr2, arr2 + m);
}

// Two O(m+n) approaches are discussed in this article - https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/
// They are: 1. Gap method- The idea: We start comparing elements that are far from each other rather than adjacent. 
// 				For every pass, we calculate the gap and compare the elements towards the right of the gap. Every pass, the gap
// 				reduces to the ceiling value of dividing by 2.
// 			 2. Find the maximum element of both array and increment it one-to avoid collision of 0 and maximum element during modulo 
// 				operation. Traverse both arrays simultaneously. Let k is the position at where the next minimum number will come. 
// 				Now update value a[k] if k<n else b[k-n] by adding min(a[i],b[j])*maximum_element. After updating all the element 
// 				divide all the elements by maximum_element so we get updated array back. 