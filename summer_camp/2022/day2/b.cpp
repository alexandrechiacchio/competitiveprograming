#include <bits/stdc++.h>
using namespace std;

const int N = 5e2+10, INF = 0x3f3f3f3f;

int adj[N*N][21];
int n, m, k, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int ans, sum, dp[N][N][30];

int to_int(pair<int, int> u){
	return m*u.first+u.second;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m-1; j++){
			cin >> adj[i*m+j][1];
			adj[i*m+j+1][3] = adj[i*m+j][1];
		}
	}
	for(int i = 1; i<=n-1; i++){
		for(int j = 1; j<=m; j++){
			cin >> adj[i*m+j][0];
			adj[(i+1)*m+j][2] = adj[i*m+j][0];
		}
	}
	if(k&1){
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				cout << "-1 ";
			}
			cout << '\n';
		}
		return 0;
	}
	memset(dp, INF, sizeof dp);
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			dp[i][j][0] = 0;
		}
	}
	for(int z = 1; z<=10; z++){
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				for(int ii = 0; ii<4; ii++) if(i+dx[ii]>0 and i+dx[ii]<=n and j+dy[ii]>0 and j+dy[ii]<=m){
					dp[i][j][z] = min({dp[i][j][z], adj[to_int({i, j})][ii]+dp[i+dx[ii]][j+dy[ii]][z-1]});
				}
			}
		}
	}
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			cout << 2*dp[i][j][k/2] << " ";
		}
		cout << '\n';
	}
	return 0;
}