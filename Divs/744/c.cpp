#include <bits/stdc++.h>
using namespace std;

int n, m, k, t;
char tb[20][20];
bool b[20][20];

void mark_points(vector<pair<int, int>> v){
	for(pair<int, int> i: v){
		b[i.first][i.second] = true;
	}
}

void find_tick(int i, int j){
	if(j<k) return;
	if(tb[i][j] == '*'){
		vector<pair<int, int>> v;
		v.push_back({i, j});
		for(int h = 1; j-h>0 and i-h>0 and j+h<=m; h++){
			if(tb[i-h][j-h] == tb[i-h][j+h] and tb[i-h][j-h]=='*'){
				v.push_back({i-h, j-h});
				v.push_back({i-h, j+h});
			} else break;
		}
		if((v.size()-1)/2>=k){
			mark_points(v);
		}
	}
}

int main(){
	cin >> t;
	while(t--){
		memset(b, 0, sizeof(b));
		cin >> n >> m >> k;
		for(int i = 1; i<=n; i++) for(int j = 1; j<=m; j++) cin >> tb[i][j];
		for(int i = 1; i<=n; i++) for(int j = 1; j<=m; j++) find_tick(i, j);
		bool ans = true;
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++) {
				if(tb[i][j]=='*' and not b[i][j]) ans = false;
			}
		}
		if(ans) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}