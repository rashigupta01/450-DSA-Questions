// Approach: maintain two heaps: max heap for first half of elements and min heap for second half of elements
// both heaps are of equal size insert it in max heap else carefully insert such that both the heaps become 
// equal size
class Solution
{
    public:
    priority_queue<int> mxheap;
    priority_queue<int, vector<int>, greater<int>> mnheap;

    //Function to insert heap.
    void insertHeap(int &x)
    {
        if (mxheap.empty()) {
            mxheap.push(x);
        } else if (mnheap.size() == mxheap.size()) {
            if (x<mnheap.top()) {
                mxheap.push(x);
            } else {
                mxheap.push(mnheap.top());
                mnheap.pop();
                mnheap.push(x);
            }
        } else {
            if (x>mxheap.top()) {
                mnheap.push(x);
            } else {
                mnheap.push(mxheap.top());
                mxheap.pop();
                mxheap.push(x);
            }
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        if (mnheap.size() == mxheap.size()) {
            return ((double)mnheap.top() + (double)mxheap.top())/2;
        } else {
            return (double) mxheap.top();
        }
    }
};