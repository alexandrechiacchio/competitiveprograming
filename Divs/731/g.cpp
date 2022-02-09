#include <bits/stdc++.h>
using namespace std;

const int N = 4e5+5;


int n, m, vis[N];
vector<int> adj[N];
bool loop[N];
queue<int> q;

bool check_loop(int a){
	if(loop[a]==true) return true;
	queue<int> qq;
	qq.push(a);
	vector<int> aux;
	bool vis1[n+5];
	memset(vis1, false, n+5);
	while(not qq.empty()){
		int u = qq.front();
		qq.pop();
		aux.push_back(u);
		for(int i: adj[u]){
			if(i==a){
				loop[a] = true;
			}
			if(not vis1[i]){
				qq.push(i);
				vis1[i] = true;
			}
		}
	}
	if(loop[a]) for(int i: aux) loop[i] = true;
	return loop[a];
}


int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 0; i<m; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
		}
		q.push(1);
		while(not q.empty()){
			int u = q.front();
			vis[u]++;
			q.pop();
			for(int i: adj[u]){
				if(vis[i]) if(check_loop(i)) continue;
				q.push(i);
			}
		}
		for(int i = 1; i<=n; i++){
			if(loop[i]) printf("-1 ");
			else if(vis[i]<2) printf("%d ", vis[i]);
			else printf("2 ");
		}
		printf("\n");
		fill(vis, vis+n+1, 0);
		for(int i = 1; i<=n; i++) adj[i].clear();
		memset(loop, false, n+1);
	}
	return 0;
}
