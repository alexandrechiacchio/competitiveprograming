#include <bits/stdc++.h>
using namespace std;


char v[60][60];
int dx[] = {-1, -1, -1, -1, 0, 1, 2, 2, 2,  2,  1,  0};
int dy[] = {-1,  0,  1,  2, 2, 2, 2, 1, 0, -1, -1, -1};

int check(int x, int y){
	int cnt = 0;
	if(v[x][y] == '*') cnt++;
	if(v[x+1][y] == '*') cnt++;
	if(v[x][y+1] == '*') cnt++;
	if(v[x+1][y+1] == '*') cnt++;
	if(cnt == 3){
		for(int i = 0; i<12; i++){
			if(v[x+dx[i]][y+dy[i]] == '*'){
				return 1;
			}
		}
		return 0;
	} 
	return 2;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n, m, cnt = 0;
		cin >> n >> m;
		memset(v, '.', sizeof v);
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				cin >> v[i][j];
				if(v[i][j] == '*') cnt++;
			}
		}
		bool flag = true;
		for(int i = 1; i<=n-1 and flag; i++){
			for(int j = 1; j<=m-1 and flag; j++){
				int aux = check(i, j);
				if(aux == 0) {
					cnt -= 3;
				} else if(aux==1){
					//cout << "found invalid L at: " << i << ' ' << j << '\n';
					flag = false;
				}
			}
		}
		if(cnt == 0 and flag) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}