#include <bits/stdc++.h>
using namespace std;

// Approach :  Build a Max-Heap of first k elements. Iterate through the rest elements if it is less than the root 
// then make it root and call heapify, else ignore it.
// Time complexity: O((n-k)*logk)
void addintoheap (int maxheap[], int k, int val) {
    maxheap[k] = val;
    int i = k;
    while(i>0 && maxheap[(i-1)/2]<maxheap[i]) {
        swap(maxheap[(i-1)/2], maxheap[i]);
        i=i/2;
    }
}

void replacemax (int maxheap[], int k, int val) {
    
    maxheap[0] = val;
    int i = 0, swapwith;
    while(i<=(k-1)/2) {
        swapwith=i;
        if(maxheap[2*i+1] > maxheap[i]) {
            swapwith=2*i+1;
        } if (maxheap[2*i+2] > maxheap[swapwith]) {
            swapwith = 2*i+2;
        }
        
        if(swapwith == i) {
            break;
        } else {
            swap(maxheap[i], maxheap[swapwith]);
        }
        i=swapwith;
    }
}

int max_heap_based (int arr[], int n, int k) {
    int maxheap[k], i;
    
    // insert first k elements into maxheap
    for(i=0; i<k; i++) {
        addintoheap(maxheap, i, arr[i]);
    }
    
    for(; i < n; i++) {
        if(arr[i]<maxheap[0]) {
            replacemax(maxheap, k, arr[i]);
        }
    }
    return maxheap[0];
}

// Approach : Quick Select - Pick a random element as pivot, move it to its correct position and partition 
// the array around it. Stop at the point where pivot itself is the kth smallest element. Reccur for one of the two
// sides of the pivot according to the position of it. 
// Worst case Time complexity - O(n^2)
// Average case Time complexity - O(n) 
int quick_select_based (int arr[], int n, int k) {
    int low = 0, high = n-1;

    while(low<=high) {
        int pivot =  (rand() % (high - low + 1)) + low, j=low;
        swap(arr[pivot], arr[high]);
        for(int i=low; i<high; i++) {
            if(arr[i]<=arr[high]) {
                swap(arr[i], arr[j++]);
            }
        }
        swap(arr[j], arr[high]);
        if(j==k-1) {
            return arr[j];
        } else if (j<k-1) {
            low = j+1;
        } else {
            high = j-1;
        }
    }
    return INT_MAX;
}

// --- Driver code
int main () {
    int t;
    ifstream infile ("in1.txt");
    ofstream outfile ("out1.txt");
    if (!infile) {
        cout<<"Input file is missing";
        return -1;
    }
    infile >> t;
    while(t--) {
        int n, k;
        infile >> n;
        infile >> k;
        int a[n];
        for(int i=0; i<n; i++) infile >> a[i];
        outfile << quick_select_based (a, n, k);
        outfile << endl;
    }
    return 0;
}



// -----------------------------Median of median approach ----------------------
#include <bits/stdc++.h>
using namespace std;

// Helper function to partition the array around the pivot
int partition(int a[], int low, int high, int pivot) 			// O(n)
{   
	int i;
	for (i=low; i<high; i++) 
		if (a[i] == pivot)  
    		break; 
	swap(a[i], a[high]); 

	i = low; 
	for (int j = low; j <= high - 1; j++) 
	{ 
		if (a[j] <= pivot) 
		{ 
			swap(a[i], a[j]); 
			i++; 
		} 
	} 
	swap(a[i], a[high]); 
	return i; 
}

// Using meadian of median approach
int kthSmallest (int a[], int k, int low, int high) {			// O(n)
    
	if(k<=0 || k>high - low + 1) {
		return INT_MAX;
	}

	int n=high-low+1;
	int medians[(int)ceil((n*1.0)/5)];
	int i;
    for(i=0; i<n/5; i++) {
        sort(a+low+i*5, a+low+(i+1)*5);
		medians[i]=a[low + 5/2];
    }
	if(n%5 != 0) {
		sort(a+low+i*5, a+low+n);
		medians[i]=a[low+(n%5)/2];
	}
	int med_of_med = (i == 1) ? medians[i-1] : kthSmallest(medians, i/2, 0, i-1);
	int pos = partition(a, low, high, med_of_med); 

    if(pos-low == k-1) return a[pos];
	else if (pos-low < k-1) return kthSmallest(a, k-pos+low-1, pos+1, high);
	else return kthSmallest(a, k, low, pos-1);
}

// --- Driver code
int main () {
    int t;
    ifstream infile ("in.txt");
    ofstream outfile ("out.txt");
    if (!infile) {
        cout<<"Input file is missing";
        return -1;
    }
    infile >> t;
    while(t--) {
        int n, k;
        infile >> n;
        infile >> k;
        int a[n];
        for(int i=0; i<n; i++) infile >> a[i];
        outfile << kthSmallest (a, k, 0, n-1);
        outfile << endl;
    }
    return 0;
}