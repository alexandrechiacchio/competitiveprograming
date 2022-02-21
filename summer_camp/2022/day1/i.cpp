#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

vector<long long> par, size;

int find(int u){
	return (par[u] == u)? u : par[u] = find(par[u]);
}

void unite(int u, int v){
	u = find(u);
	v = find(v);
	if(u==v) return;
	if(size[u]<size[v]) swap(u, v);
	size[u] += size[v];
	par[v] = u;
}


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		par.resize(n+1);
		size.resize(n+1);
		fill(size.begin(), size.end(), 1);
		for(int i = 1; i<=n; i++) par[i] = i;
		for(int i = 0; i<m; i++){
			int a, b;
			cin >> a >> b;
			unite(a, b);
		}
		set<int> s;
		for(int i = 1; i<=n; i++){
			s.insert(find(i));
		}
		long long ways = 1;
		for(int i: s){
			ways = (ways*size[i])%MOD;
		}
		cout << s.size() << " " << ways << '\n';
	}
	return 0;
}