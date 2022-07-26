// https://www.geeksforgeeks.org/merge-k-sorted-arrays/
/*
The process might begin with merging arrays into groups of two. After the first merge, we have k/2 arrays. 
Again merge arrays in groups, now we have k/4 arrays. This is similar to merge sort. 
Divide k arrays into two halves containing an equal number of arrays until there are two arrays in a group.
*/

/*
Alternative
 Efficient Approach: The idea is to use Min Heap. This MinHeap based solution has the same time complexity which 
is O(NK log K). But for a different and particular sized array, this solution works much better. The process must start with 
creating a MinHeap and inserting the first element of all the k arrays. Remove the root element of Minheap and put it in the 
output array and insert the next element from the array of removed element. To get the result the step must continue until 
there is no element in the MinHeap left. 
*/
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (int i=0; i<K; i++) {
        pq.push({arr[i][0], {i, 0}});
    }
    vector<int> res;
    while (!pq.empty()) {
        auto temp = pq.top();
        pq.pop();
        res.push_back(temp.first);
        if (temp.second.second < arr[temp.second.first].size()-1) {
            pq.push({arr[temp.second.first][temp.second.second+1], {temp.second.first, temp.second.second+1}});
        }
    }
    return res;
}