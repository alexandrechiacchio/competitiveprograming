#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

vector<int> adj[N];
int depth[N], n, cnteven, cntodd, w_odd[N], w_even[N], ceven, codd;
queue<int> q;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i<n-1; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	q.push(1);
	while(not q.empty()){
		int u = q.front();
		q.pop();
		for(int i: adj[u]) if(not depth[i]){
			q.push(i);
			depth[i] = depth[u] + 1;
		}
	}
	fill(w_odd, w_odd+n+1, 1);
	fill(w_even, w_even+n+1, 1);
	cntodd = n;
	cnteven = n;
	for(int i = 1; i<=n; i++){
		if(depth[i]&1){
			w_odd[i] = adj[i].size();
			cntodd += adj[i].size()-1;
			codd++;
		} else {
			w_even[i] = adj[i].size();
			cnteven += adj[i].size()-1;
			ceven++;
		}
	}
	if(n==2) codd = 2;
	if(codd>ceven){
		cout << codd << " " << cntodd << '\n';
		for(int i = 1; i<=n; i++) cout << w_odd[i] << " ";
		cout << '\n';
	} else if(codd<ceven){
		cout << ceven << " " << cnteven << '\n';
		for(int i = 1; i<=n; i++) cout << w_even[i] << " ";
		cout << '\n';
	} else {
		if(cntodd<cnteven){
			cout << codd << " " << cntodd << '\n';
			for(int i = 1; i<=n; i++) cout << w_odd[i] << " ";
			cout << '\n';
		} else {
			cout << ceven << " " << cnteven << '\n';
			for(int i = 1; i<=n; i++) cout << w_even[i] << " ";
			cout << '\n';
		}
	}
	return 0;
}