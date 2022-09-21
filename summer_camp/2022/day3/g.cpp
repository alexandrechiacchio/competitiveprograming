//not finished
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj1;
vector<vector<int>> adj2;



int find_max_height(vector<vector<int>>& adj) {
	//double dfs, first one to find a most distant leaf
	//second one to find max dist(height)
	bool vis[adj.size()];
	memset(vis, false, sizeof vis);
	int dist[adj.size()];
	memset(dist, 0, sizeof dist);
	int most_distant_node, max_dist = 0;
	queue<int> q;
	q.push(1);
	vis[1] = true;
	while (not q.empty()) {
		int u = q.front();
		q.pop();
		for (int i : adj[u]) if (not vis[i]) {
			q.push(i);
			dist[i] = dist[u] + 1;
			vis[i] = true;
			if (dist[i] > max_dist) {
				most_distant_node = i;
				max_dist = dist[i];
			}
		}
	}
	memset(vis, 0, sizeof vis);
	memset(dist, 0, sizeof dist);
	max_dist = 0;
	q.push(most_distant_node);
	vis[most_distant_node] = true;
	while (not q.empty()) {
		int u = q.front();
		q.pop();
		for (int i : adj[u]) if (not vis[i]) {
			q.push(i);
			dist[i] = dist[u] + 1;
			vis[i] = true;
			max_dist = max(max_dist, dist[i]);
		}
	}
	return max_dist;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	adj1.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj1[u].push_back(v);
		adj1[v].push_back(u);
	}
	cin >> m;
	adj2.resize(m + 1);
	for (int i = 0; i < m - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj2[u].push_back(v);
		adj2[v].push_back(u);
	}
	if (find_max_height(adj1) > find_max_height(adj2)/2) cout << "GGEZ\n";
	else cout << "FF\n";
	return 0;
}