#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

vector<int> p;

void sieve(){
	bool pr[N];
	memset(pr, 0, sizeof pr);
	for(int i = 2; i*i<N; i++){
		if(pr[i]) continue;
		for(int j = i*i; j<N; j+=i){
			pr[j] = true;
		}
	}
	for(int i = 2; i<N; i++) if(not pr[i]) p.push_back(i);
}

vector<vector<pair<int, int>> adj;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	sieve();
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		adj.resize(n);
		for(int i = 0; i<n; i++){
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
			
		}

	}
	return 0;
}