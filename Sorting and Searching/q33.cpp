
// MEET IN THE MIDDLE ALGORITHM: https://www.geeksforgeeks.org/meet-in-the-middle/
// Revise the algorithm, useful


// Then just use meet in the middle and binary search
#include <bits/stdc++.h>
using namespace std;
 
#define lld long long int
 
lld c = 0;
 
void subsets (vector<lld> &v, lld pos, lld sum, vector<lld> &res) {
	if (pos == v.size()) {
		res.push_back(sum);
		return;
	}
 
	subsets (v, pos+1, sum, res);
	subsets (v, pos+1, sum+v[pos], res);
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lld n, a, b;
	cin>>n>>a>>b;
 
	vector<lld> v;
	lld i = 0;
	lld x ;
	for (; i<n/2; i++) cin>>x, v.push_back(x);
	vector<lld> first;
	subsets (v, 0, 0, first);
 
	v.clear();
	for (lld j = 0; i<n; i++, j++) cin>>x, v.push_back(x);
	vector<lld> second;
	subsets (v, 0, 0, second);
 
	sort (second.begin(), second.end());
 
	for (i=0; i<first.size(); i++) {
		lld low = lower_bound (second.begin(), second.end(), a-first[i])-second.begin();
		lld high = upper_bound (second.begin(), second.end(), b-first[i])-second.begin();

		c += high - low;
	}
 
	cout << c;
 
	return 0;
}