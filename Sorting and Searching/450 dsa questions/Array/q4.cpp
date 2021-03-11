// Approach 1: create three count variables for 0, 1 and 2. Then first place all 0, then all 1, and then all 2.
void sort012(int a[], int n)
{
    int count0 = 0, count1=0, count2=0;
    for(int i=0; i<n; i++) {
        if(a[i]==0) {
            count0++;
        } else if(a[i] == 1) {
            count1++;
        } else {
            count2++;
        }
    }
    int j=0;
    for(int i=0; i<count0; i++) {
        a[j++] = 0;
    }
    for(int i=0; i<count1; i++) {
        a[j++] = 1;
    }
    for(int i=0; i<count2; i++) {
        a[j++] = 2;
    }
    return;
}

// Approach 2: Dutch National Flag Algorithm OR 3-way Partitioning
// There are three indices – low, mid and high. Low(just next index after all zeros) Mid(Element being processed) High(just previous index before all two's)
// If curr element is 0 swap with low, is 1 do nothing, else swap with high