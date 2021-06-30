// My approach: similar to kadane's alogrithm
// https://www.geeksforgeeks.org/maximum-difference-zeros-ones-binary-string/
class Solution{
public:	
	int maxSubstring(string S)
	{
	    int count = -1, res = -1;
	    for (int i=0; i<S.size(); i++) {
	        if (count==-1) {
	            if (S[i]=='0') count = 1;
	        } else {
	            count += S[i]=='1' ? -1 : 1;
	        }
	        res = max (res, count);
	    }
	    return res;
	}
};