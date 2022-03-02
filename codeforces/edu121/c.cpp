#include <bits/stdc++.h>
using namespace std;


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	long long t;
	cin >> t;
	while(t--){
		long long ans = 0, n;
		cin >> n;
		vector<pair<long long, long long>> v(n+1);
		for(long long i = 1; i<=n; i++) cin >> v[i].first;
		for(long long i = 1; i<=n; i++) cin >> v[i].second;
		sort(v.begin(), v.end());
		vector<long long> u(n+1);
		for(long long i = 1; i<=n; i++){
			if(v[i].second<=v[i].first-v[i-1].first){ //eh resetable
				ans+=(1+v[i].second)*v[i].second/2;
			} else {
				ans+= (v[i-1].second+1+v[i-1].second+v[i].first-v[i-1].first)*(v[i].first-v[i-1].first)/2;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}