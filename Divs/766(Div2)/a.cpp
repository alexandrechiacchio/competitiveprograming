#include <bits/stdc++.h>
using namespace std;

char grid[60][60];

bool check(int n, int m){
	bool ans = true;
	for(int i = 0; i<n; i++) for(int j = 0; j<m; j++) if(grid[i][j] == 'B') ans = false;
	return ans;
}

bool check_lines(int n, int m, int r, int c){
	bool ans = false;
	for(int i = 0; i<m; i++) if(grid[r][i]=='B') ans = true;
	for(int i = 0; i<n; i++) if(grid[i][c]=='B') ans = true;
	return ans;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n, m, r, c;
		cin >> n >> m >> r >> c;
		for(int i = 0; i<n; i++){
			cin >> grid[i];
		}
		if(check(n, m)) cout << "-1\n";
		else if(grid[r-1][c-1] == 'B') cout << "0\n";
		else if(check_lines(n, m, r-1, c-1)) cout << "1\n";
		else cout << "2\n";
	}
	return 0;
}