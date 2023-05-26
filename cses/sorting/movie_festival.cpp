#include <bits/stdc++.h>
using namespace std;


bool comp(pair<int, int> u, pair<int, int> v){
	return u.second<v.second or (u.second == v.second and u.first<v.first);
}

int main(){
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for(int i = 0; i<n; i++) cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end(), comp);
	int ans = 0, last_movie = -1;
	for(int i = 0; i<n; i++){
		if(v[i].first >= last_movie){
			ans++;
			last_movie = v[i].second;
		}
	}
	cout << ans << '\n';
	return 0;
}