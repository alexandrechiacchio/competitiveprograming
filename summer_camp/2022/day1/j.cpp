#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

vector<int> c(N), chi(N);
set<int> p;
vector<bool> vis(N);

int ans;

void find_loop(int u){
	int cost = c[u];
	int a = chi[u];
	while(a!=u){
		cost = min(c[a], cost);
		a = chi[a];
	}
	ans+= cost;
}

void dfs1(int u){
	if(vis[u]) return;
	else{
		vis[u] = true;
		p.insert(u);
	}
	if(chi[u] == u){
		ans+= c[u];
		return;
	}
	if(p.find(chi[u]) != p.end()){
		find_loop(u);
	}
	else if(not vis[chi[u]]) dfs1(chi[u]);
}

int main(){
	int n;
	cin >> n;
	for(int i = 1; i<=n; i++) cin >> c[i];
	for(int i = 1; i<=n; i++) cin >> chi[i];
	for(int i = 1; i<=n; i++){
		if(not vis[i]){
			p.clear();
			dfs1(i);
		}
	}
	cout << ans << '\n';
	return 0;
}