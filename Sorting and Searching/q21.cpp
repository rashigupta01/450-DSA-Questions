#include <bits/stdc++.h>
using namespace std;

#define ll long long int

vector<pair<ll, ll>> merge (vector<pair<ll, ll>> v) {
	sort (v.begin(), v.end());
	vector<pair<ll, ll>> result;
	pair<ll, ll> last = v[0];
	for (ll i=1; i<v.size(); i++) {
		if (v[i].first > last.second+1) {
			result.push_back(last);
			last = v[i];
		} else {
			last.second = max (last.second, v[i].second);
		}
	}
	result.push_back(last);
	return result;
}

int main() {
	ll t;
	cin>>t;
	while (t--) {
        ll n, q;
        cin>>n>>q;
        vector<pair<ll, ll>> range;
        for (ll i=0; i<n; i++) {
            ll a, b;
            cin>>a>>b;
            range.push_back({a, b});
        }
        range = merge (range);
        n = range.size();

        for (ll i=0; i<q; i++) {
            ll query;
            cin>>query;
            ll number = range[0].first;
            ll rank = 1;
            for (ll i=0; i<n; i++) {
                if (query <= rank+(range[i].second - range[i].first)) {
                    cout << number + query-rank;
                    break;
                } else {
                    if (i==n-1) {
                        cout << -1;
                    } else {
                        number = range[i+1].first;
                        rank += range[i].second - range[i].first + 1;
                    }
                }
            }
            cout << endl;
        }
	}
	return 0;
}