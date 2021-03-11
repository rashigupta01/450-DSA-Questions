
// Approach 1: For every element find the largestLeft and largestRight and find min of them. That is the hight of water column at 
// that index. (TC-O(n^2) SC-O(1))

// Approach 2: For every element instead of finding largest on left and right in an iteration, we can pre-compute left and right 
// largest for each element. The height of water coloumn at an index would be min(left[i], right[i]). (TC-O(n) SC-O(n))

//  Approach 3: (a bit complex) I implemented using stacks. Go through the code below. (TC-O(n) SC-O(n))
int trappingWater(int arr[], int n){

    stack<int> s;
    vector<int> block(n+1);
    block[0]=0;
    for(int i=1; i<n; i++) {
        block[i] = block[i-1] + arr[i-1];
    }
    
    int i=1, water=0;
    s.push(0);
    while(i<n) {
        if(arr[i] < arr[s.top()]) {
            water += (i-s.top()-1)*arr[i] - (block[i]-block[s.top()+1]);
            s.push(i);
            i++;
        } else {
            int temp = s.top();
            s.pop();
            if(s.empty()) {
                water += (i-temp-1)*arr[temp] - (block[i]-block[temp+1]);
                s.push(i);
                i++;
            } else {
                water -= (temp-s.top()-1)*arr[temp] - (block[temp]-block[s.top()+1]);
            }
            
        }
    }
    return water;
    
}