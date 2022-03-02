#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1, INF = 1e9;
struct edge { int v, c, f; };

int n, m, src, snk, h[N], ptr[N], t, total_price;
vector<edge> edgs;
vector<int> g[N];

void add_edge(int u, int v, int c) {
	int k = edgs.size();
	edgs.push_back({ v, c, 0 });
	edgs.push_back({ u, 0, 0 });
	g[u].push_back(k);
	g[v].push_back(k + 1);
}

void clear() {
	memset(h, 0, sizeof h);
	memset(ptr, 0, sizeof ptr);
	edgs.clear();
	for (int i = 0; i < N; i++) g[i].clear();
	src = 0;
	snk = N - 1;
}

bool bfs() {
	memset(h, 0, sizeof h);
	queue<int> q;
	h[src] = 1;
	q.push(src);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i : g[u]) {
			int v = edgs[i].v;
			if (!h[v] and edgs[i].f < edgs[i].c)
				q.push(v), h[v] = h[u] + 1;
		}
	}
	return h[snk];
}

int dfs(int u, int flow) {
	if (!flow or u == snk) return flow;
	for (int& i = ptr[u]; i < g[u].size(); ++i) {
		edge& dir = edgs[g[u][i]], & rev = edgs[g[u][i] ^ 1];
		int v = dir.v;
		if (h[v] != h[u] + 1)  continue;
		int inc = min(flow, dir.c - dir.f);
		inc = dfs(v, inc);
		if (inc) {
			dir.f += inc, rev.f -= inc;
			return inc;
		}
	}
	return 0;
}

int dinic() {
	int flow = 0;
	while (bfs()) {
		memset(ptr, 0, sizeof ptr);
		while (int inc = dfs(src, INF)) flow += inc;
	}
	return flow;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--){
		clear();
		cin >> n >> m;
		total_price = 0;
		//the idea is to connect src to vouchers to items to snk
		//prices of itens
		for(int i = 1; i<=n; i++){
			int a;
			cin >> a;
			total_price += a;
			add_edge(m+i, snk, a);
		}
		//value of vouchers
		for(int i = 1; i<=m; i++){
			int a;
			cin >> a;
			add_edge(src, i, a);
		}
		//what items are the vouchers connected to
		for(int i = 1; i<=m; i++){
			int k;
			cin >> k;
			for(int j = 0; j<k; j++){
				int a;
				cin >> a;
				add_edge(i, m+a, INF);
			}
		}
		cout << total_price-dinic() << '\n';
	}
return 0;
}