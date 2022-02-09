#include <bits/stdc++.h>
using namespace std;


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n, root;
		cin >> n;
		vector<int> b(n), p(n), level(n);
		for(int i = 0; i<n; i++){
			cin >> b[i];
			if(b[i] == i) root = i;
		}
		for(int i = 0; i<n; i++) cin >> p[i];
		//bfs
		queue<int> q;
		
	}
	return 0;
}