#include <bits/stdc++.h>
using namespace std;


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		long long value = LONG_LONG_MAX;
		cin >> n;
		vector<pair<pair<long long, long long>, long long>> v(n);
		for(long long i = 0; i<n; i++){
			cin >> v[i].first.first >> v[i].first.second >> v[i].second;
		}
		set<pair<long long, long long>> l, r;
		set<pair<pair<long long, long long>, long long>> c;
		for(long long i = 0; i<n; i++){
			auto it_l = *l.begin(), it_r = *r.begin();
			if(v[i].first.first < it_l.first){
				l.clear();
				value = LONG_LONG_MAX;
			}
			if((v[i].first.first <= it_l.first) or i==0) l.insert({v[i].first.first, v[i].second});
			it_l = *l.begin();

			if(-v[i].first.second < it_r.first){
				r.clear();
				value = LONG_LONG_MAX;
			}
			if((-v[i].first.second <= it_r.first) or i==0) r.insert({-v[i].first.second, v[i].second});
			it_r = *r.begin();
			
			if(v[i].first.first == it_l.first and -v[i].first.second == it_r.first or i==0) value = min(v[i].second, value);

			cout << min(it_r.second+it_l.second, value) << '\n';

		}

	}
	return 0;
}