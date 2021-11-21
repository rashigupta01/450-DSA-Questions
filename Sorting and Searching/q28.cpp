// Find the missing number in Arithmetic Progression
// Algo i thought of (similar on gfg) -
// 1. find 'a' and 'd' using first element, last element, size of array
// 2. do binary search, if mid is midth element that means missing element is from mid...high and vice versa



// the link of the question in sheet point to some basic ques... here is its solution
class Solution{
public:
    int inSequence(int A, int B, int C){
        // cout << (B-A)%C  << endl;
        if (A==B) return 1;
        if ((B-A<0)^(C<0)) return 0;
        if (C==0) return A==B;
        if ((B-A)%C == 0) return 1;
        return 0;
    }
};