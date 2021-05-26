// greedy wont work in this case.
// eg: 3155 after two swaps --> 5513 or 5531 
//     1355 after two swaps --> 5513 or 5531
// so we have to try all possible swaps with max 

// NOTE: Greedy works when elements are distinct
class Solution
{
    public:
    string result;
    
    void util (string str, int k, int pos) {
        if (pos == str.size() || k==0) {
            result = max (result, str);
            return;
        }
        
        int mxpos=pos;
        for (int i=pos+1; i<str.size(); i++) {
            if (str[mxpos] < str[i]) mxpos = i;
        }
        
        if (str[mxpos] == str[pos]) {
            util (str, k, pos+1);
            return;
        }
        
        for (int i=pos+1; i<str.size(); i++) {
            if (str[i] == str[mxpos]) {
                swap(str[pos], str[i]);
                util (str, k-1, pos+1);
                swap(str[pos], str[i]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
        result = str;
        util (str, k, 0);
        return result;
    }
};