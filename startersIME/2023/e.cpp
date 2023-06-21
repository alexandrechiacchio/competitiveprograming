#include <bits/stdc++.h>
using namespace std;

const int N = 1e7+7;

vector<int> par(N), sz(N, 1);

int find(int u){
	if(par[u]!=u) u = find(par[u]);
	return u;
}

void add(int u, int v){
	 u = find(u);
	 v = find(v);
	if(u==v) return;

	if(u < v) swap(u, v);

	par[v] = u;
	sz[u]+= sz[v];
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	for(int i = 1; i<N; i++) par[i] = i;
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i<n; i++) cin >> a[i];
	vector<pair<int, int>> edges(m);
	for(int i = 0; i<m; i++){
		pair<int, int> aux;
		cin >> aux.first >> aux.second;
		aux.first = a[aux.first-1];
		aux.second = a[aux.second-1];
		if(aux.second > aux.first) swap(aux.first, aux.second);
		edges[i] = aux;
	}
	sort(edges.begin(), edges.end());
	int ans = 1;
	for(int i = 0; i<m; i++){
		add(edges[i].first, edges[i].second);
		if(sz[edges[i].first] == edges[i].first) ans = edges[i].first;
	}
	cout << ans << '\n';
	return 0;
}