#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

vector<int> v(N);
int n, m;
vector<vector<long long>> dp(N, vector<long long>(110));

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	if(v[1] == 0) for(int i = 1; i<=m; i++) dp[1][i] = 1;
	else dp[1][v[1]] = 1;
	for (int i = 2; i <= n; i++) {
		if(v[i] == 0) for (int j = 1; j <= m; j++) {
			dp[i][j] = (dp[i][j] + dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % MOD;
		}
		else {
			dp[i][v[i]] = (dp[i][v[i]] + dp[i-1][v[i]-1] + dp[i-1][v[i]] + dp[i-1][v[i]+1])%MOD;
		}
	}
	long long ans = 0;
	for(int i = 1; i<=m; i++) ans = (ans + dp[n][i] + MOD)%MOD;
	cout << ans <<  '\n';
	return 0;
}