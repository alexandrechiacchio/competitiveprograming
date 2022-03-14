#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

set<int> adj[N];
bool vis[N];
int sz[N], dist[N], n;

void dfs(int node){
	for(int i: adj[node]){
		if(not vis[i]){
			vis[i] = true;
			dfs(i);
			sz[node] += sz[i];
		}
	}
	sz[node]++;
}

int find_centroid(int node){
	int ans;
	memset(dist, 0, sizeof dist);
	memset(vis, 0, sizeof vis);
	queue<int> q;
	q.push(node);
	vis[node] = true;
	int max = 0;
	while(not q.empty()){
		int u = q.front();
		q.pop();
		for(int i: adj[u]){
			if(not vis[i]){
				dist[i] = dist[u] + 1;
				vis[i] = true;
				q.push(i);
				if(max < dist[i]){
					node = i;
					max = dist[i];
				}
			}
		}
	}
	memset(sz, 0, sizeof sz);
	memset(vis, 0, sizeof vis);
	vis[node] = true;
	dfs(node);
	max = 0;
	for(int i = 1; i<=n; i++){
		if(sz[i]>max and sz[i]-1<=(sz[node]+1)/2 and vis[i]){
			ans = i;
			max = sz[i];
		}
	}
	return ans;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n-1; i++){
		int a, b;
		cin >> a >> b;
		adj[a].insert(b);
		adj[b].insert(a);
	}
	int node_to_cut = 1, centroid;
	while(true){
		centroid = find_centroid(node_to_cut);
		cout << "? 2 " << centroid << endl;
		cin >> node_to_cut;
		if(node_to_cut == 0) break;
		adj[node_to_cut].erase(adj[node_to_cut].find(centroid));
		adj[centroid].erase(adj[centroid].find(node_to_cut));
	}
	cout << "! " << centroid << endl;
	return 0;
}