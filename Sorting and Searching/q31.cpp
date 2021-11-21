
// Entirely Binary search can be considered by specifying max value as 10*n*(n+1)/2 
#include <bits/stdc++.h>
using namespace std;

int count ( int r, int t) {
	return (sqrt (1 + (8*t*1.0/r))-1)/2;
}

int amt (int t, vector<int> v) {
	int c = 0;
	for (auto r : v) {
		c += count (r, t);
	}
	return c;
}

int bs (int low, int high, int p, vector<int> v) {
	int ans, mid;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (amt(mid, v) >= p) {
			ans = mid;
			high = mid-1;
		} else {
			low = mid+1;
		}
	}
	return ans;
}

int main() {
	int t;
	cin>>t;
	while (t--) {
		int p;
		cin>>p;
		int l;
		cin>>l;
		vector<int> v(l);
		for (int i = 0; i<l; i++) cin >> v[i];
		
		if (p==0) {cout << 0; continue; }
		int t = 1;
		while (amt(t, v) < p) {
			t*=2;
		}
		cout << bs (t/2, t, p, v) << endl;
	}
	return 0;
}