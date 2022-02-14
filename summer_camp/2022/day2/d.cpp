#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int main(){
	while(cin.peek()!=EOF){
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i<n; i++) cin >> v[i];
		int m;
		cin >> m;
		vector<int> d(m);
		for(int i = 0; i<m; i++) cin >> d[i];
		vector<int> vis(N);
		queue<int> q;
		q.push(0);
		while(not q.empty()){
			int u = q.front();
			q.pop();
			for(int i = 0; i<n; i++){
				if(vis[u]<2 and u+v[i]<N){
					q.push(u+v[i]);
					vis[u+v[i]] = vis[u]+1;
				}
			}
		}
		int ans = 0;
		for(int i = 0; i<m; i++) if(vis[d[i]]) ans++;
		cout << ans << '\n';
	}
	return 0;
}