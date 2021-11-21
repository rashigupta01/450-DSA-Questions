#include <bits/stdc++.h>
using namespace std;

int main() {
	while (true) {
		int n;
		cin>>n; 
		if (!n) break;
		vector<int> a(n);
		for (int i=0; i<n; i++) cin>>a[i];
		int m;
		cin>>m; 
		vector<int> b(m);
		for (int i=0; i<m; i++) cin>>b[i];
		
		int first = 0, second=0, result = 0;
		int p1 = 0, p2 = 0;
		while (p1<n && p2<m) {
			if (a[p1] < b[p2]) {
				first += a[p1];
				p1++;
			} else if (a[p1] > b[p2]) {
				second += b[p2];
				p2++;
			} else {
				result += max (first, second);
				result += a[p1];
				first = 0; second = 0;
				p1++;
				p2++;
			}
		}
		
		while (p1<n) {
			first += a[p1]; p1++;
		}
		while (p2<m) {
			second += b[p2]; p2++;
		}
		result += max (first, second);
		cout << result << endl;
	}
	return 0;
}