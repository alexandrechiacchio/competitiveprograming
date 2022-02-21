#include <bits/stdc++.h>
using namespace std;


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<pair<int, pair<int, int>>> v(m);
	for(int i = 0; i<n; i++){
		cin >> v[i].first >> v[i].second.first >> v[i].second.second;
	}
	vector<pair<char, int>> ans(n);
	queue<int> q;
	q.push(0);
	while(not q.empty()){
		auto u = 
	}
	return 0;
}