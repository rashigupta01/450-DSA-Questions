// Approach 1:
// Keep subtracting divisor from dividend till dividend > divisor and return the no of times subtraction operation is performed

// Approach 2: consider quotient a binary number 
// Refer : https://leetcode.com/problems/divide-two-integers/discuss/13407/C%2B%2B-bit-manipulations
// if the code below isn't clear
class Solution {
public:
    int divide(int dividend, int divisor) {
        
        // covering edge cases
        if (dividend == INT_MIN) {
            if (divisor==1) return INT_MIN;
            else if (divisor == -1) return INT_MAX;
            else return divisor&1 ? divide(dividend+1, divisor) : divide(dividend>>1, divisor>>1);
        }
        if (divisor == INT_MIN) {
            return 0;
        }

        int quotient = 0;
        int sign = ((divisor<0) ^ (dividend<0));
        dividend = abs (dividend);
        divisor = abs (divisor);
        
        while (dividend >= divisor) {
            int temp = divisor, count=0;
            while (temp<<1 <= dividend && (temp<<1)>0) {
                temp = temp << 1;
                count++;
            }
            quotient += pow (2, count);
            dividend -= temp;
        }
        return sign==1 ? -quotient : quotient;
    }
};

// Another approach on gfg : https://www.geeksforgeeks.org/divide-two-integers-without-using-multiplication-division-mod-operator/
 int divide(long long dividend, long long divisor) {
 
   int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
 
  dividend = abs(dividend);
  divisor = abs(divisor);
 
  long long quotient = 0, temp = 0;
 
  for (int i = 31; i >= 0; --i) {
    if (temp + (divisor << i) <= dividend) {
      temp += divisor << i;
      quotient |= 1LL << i;
    }
  }
 
  return sign * quotient;
}