#include <bits/stdc++.h>
using namespace std;

int n, m;



int dist(pair<int, int> p, pair<int, int> q){
	return abs(p.first-q.first)+abs(p.second-q.second);
}

int set_dist(pair<int, int> p){
	return max({dist(p, {0,0}), dist(p, {n-1,0}), dist(p, {0,m-1}), dist(p, {n-1,m-1})});
}



int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t; 
	cin >> t;
	while(t--){
		cin >> n >> m;
		multiset<int> ms;
		vector<vector<int>> grid(n);
		for(int i = 0; i<n; i++) grid[i].resize(m);
		for(int i = 0; i<n; i++) for(int j = 0; j<m; j++) ms.insert(set_dist({i, j}));
		for(int i = 0; i<n*m; i++){
			auto p = *ms.begin();
			cout << p << " ";
			ms.erase(ms.begin());
		}
		cout << '\n';
	}
	return 0;
}