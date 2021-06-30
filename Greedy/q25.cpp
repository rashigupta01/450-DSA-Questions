// sort and find the largest height and width and print their area

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int w, h, n;
		cin>>w>>h>>n;
		vector<int> x(w+2), y(h+2);
		x[0]=y[0]=0;
		for (int i=1; i<=n; i++) {
			cin>>x[i];
			cin>>y[i];
		}
		x[w+1]=w+1;
		y[h+1] = h+1;
		
		sort (x.begin(), x.end());
		sort (y.begin(), y.end());
		
		int width = 0, height=0;
		for (int i=0; i<=w; i++) {
			width = max (width, x[i+1]-x[i]-1);
		}
		for (int i=0; i<=h; i++) {
			height = max (height, y[i+1]-y[i]-1);
		}
		cout<< width*height<<endl;
	}
	return 0;
}