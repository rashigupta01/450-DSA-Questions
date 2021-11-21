class Solution
{
    public:
        int no_of_zeros (int num) {
            int powerof5 = 5, zeros = 0;
            while (powerof5 <= num) {
                zeros += num/powerof5;
                powerof5 *= 5;
            }
        	return zeros;
        }

        int bs (int low, int high, int n) {
        	int ans, mid;
        	while (low <= high) {
        		int mid = (low + high) / 2;
        		if (no_of_zeros(mid) >= n) {
        			ans = mid;
        			high = mid-1;
        		} else {
        			low = mid+1;
        		}
        	}
        	return ans;
        }
        int findNum(int n)
        {
            int num = 1;
    		while (no_of_zeros(num) < n) {
    			num*=5;
    		}
    		return bs (num/5, num, n);
        }
};