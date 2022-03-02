//incomplete
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

vector<vector<int>> par(N, vector<int>(20)), children(N);
vector<int> d(N);

void dfs(int root){
	queue<int> q;
	q.push(root);
	par[1][0] = 1;
	for(int j = 0; j<depth; j++){
		par[1][j+1] = par[par[1][j]][j];
	}
	while(not q.empty()){
		int u = q.front();
		q.pop();
		for(int i: children[u]){
			dist[i] = dist[u]+1;
			par[i][0] = u;
			q.push(i);
			for(int j = 0; j<depth; j++){
				par[i][j+1] = par[par[i][j]][j];
			}
		}
	}
}

int lca(int u, int v){
	//making sure u is deeper in the tree
	if(dist[v]>dist[u]) swap(u, v);
	//finding the parent of u thats on the same depth of v using binary lifting
	int k = dist[u]-dist[v];
	for(int i = 0; i<depth; i++){
		if(k & (1<<i)){
			u = par[u][i];
		}
	}
	//if v is ancestor of u
	if(u==v) return v;
	//rising in the tree with powers of 2
	for(int i = depth-1; i>=0; i--){
		if(par[u][i] != par[v][i]){
			u = par[u][i];
			v = par[v][i];
		}
	}
	//now, u and v are the children of the lca
	return par[u][0];
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i<=n; i++) cin >> d[i];
	for(int i = 1; i<m; i++){
		int a, b;
		cin >> a >> b;
		children[m+i].push_back(find(a));
		children[m+i].push_back(find(b));
	}

	return 0;
}