#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1, INF = 1e9;
const int M = 1e2+10;

int t, n, board[M][M];
struct edge { int v, c, f; };

int src = 0, snk = N-1, h[N], ptr[N];
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

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

void add_edges(int x, int y){
	for(int i = 0; i<4; i++){
		if(x+dx[i]>0 and x+dx[i]<=n and y+dy[i]>0 and y+dy[i]<=n){
			if(board[x+dx[i]][y+dy[i]]==board[x][y]+1){
				add_edge(x*n+y, (x+dx[i])*n+y+dy[i], 1);
			}
		}
	}
}

int v[10];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while(t--){
		clear();
		cin >> n;
		memset(v, 0, sizeof v);
		for(int i = 1; i<=n; i++) {
			for(int j = 1; j<=n; j++){
				cin >> board[i][j];
				v[board[i][j]]++;
			}
		}
		bool ans = true;
		for(int k = 1; k<10; k++){
			clear();
			for(int i = 1; i<=n; i++) {
				for(int j = 1; j<=n; j++){
					if(board[i][j]==k){
						add_edge(src, i*n+j, 1);
						add_edges(i, j);
					}
					if(board[i][j]==k+1) add_edge(i*n+j, snk, 1); 
				}
			}
			if(dinic()!=v[k+1]) ans = false;
		}
		if(ans) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}