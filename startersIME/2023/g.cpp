#include <bits/stdc++.h>
using namespace std;


struct Edge {
	int from;
	int to;
	int cost;
	Edge(int _from, int _to,int _cost){
		from = _from;
		to = _to;
		cost = _cost;
	}
};

bool cmp(Edge* u, Edge* v){
	return u->cost < v->cost;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	vector<Edge*> edges(m);
	priority_queue<Edge*> pq(cmp);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[i] = new Edge(a, b, c);
		pq.push(edges[i]);
	}
	while(!pq.empty()){
		Edge* u = pq.top();
		pq.pop();
		cout << u->cost << '\n';
	}
	return 0;
}