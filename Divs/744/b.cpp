#include <bits/stdc++.h>
using namespace std;



int t, n, a[100], aux[100];

void cycle(int l, int r, int d){
	for(int i = l; i<r; i++) swap(a[i], a[r]);
}

int find_pos(int u, int p){
	for(int i = p; i<n; i++) if(a[i] == u) return i;
}

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i<n; i++) cin >> a[i], aux[i] = a[i];
		sort(aux, aux+n);
		vector<pair<int, int>> ans;
		for(int i = 0; i<n; i++){
			int pos;
			if(a[i]!=aux[i]){
				pos = find_pos(aux[i], i);
				ans.push_back({i+1, pos+1});
				cycle(i, pos, 1);
			}
		}
		cout << ans.size() << "\n";
		for(pair<int, int> i: ans) cout << i.first << " " << i.second << " " << i.second-i.first << "\n";
	}
	return 0;
}