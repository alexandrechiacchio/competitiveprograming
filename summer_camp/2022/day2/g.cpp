#include <bits/stdc++.h>
using namespace std;
 
const int N = 5e2+10;
 
int n, l, k, dp[N][N], d[N], a[N];
 
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> l >> k;
	for(int i = 0; i<n; i++) cin >> d[i];
	d[n] = l;
	for(int i = 0; i<n; i++) cin >> a[i];
	for(int i = 1; i<=n; i++){
		for(int j = 0; j<=k; j++){
			dp[i][j] = dp[i-1][j] + (d[i]-d[i-1])*a[i-1];
		}
	}
	for(int z = 1; z<=k; z++){
		for(int i = 1; i<=n; i++){
			for(int j = 0; j<=z and j<i; j++){
				dp[i][z] = min(dp[i-j-1][z-j] + (d[i]-d[i-j-1])*a[i-j-1], dp[i][z]);
			}
		}
	}
	cout << dp[n][k];
	return 0;
}