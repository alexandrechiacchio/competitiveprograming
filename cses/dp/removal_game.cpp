#include <bits/stdc++.h>
using namespace std;
 

int main() {
	int n;
	cin >> n;
	vector<int> v(n + 10);
	vector<vector<int>> dp(n+10, vector<int>(n+10, INT_MIN));
	vector<vector<int>> dp2(n+10, vector<int>(n+10, INT_MIN));
	for (int i = 1; i <= n; i++){
		cin >> v[i];
		dp[i][0] = 0;
	}
	for (int k = 1; k <= n; k++) {
		for(int i = 1; i+k-1<=n; i++){
			if((k+n)&1)	dp[i][k] = max(dp[i-1][k-1] + v[i-1], dp[i+1][k-1] + v[i+k-1]);
			else dp[i][k] = max(dp[i-1][k-1], dp[i+1][k-1]);
		}
	}
	cout << '\n';
	for(int i = 0; i<=n; i++){
		for(int j = 0; i+j<=n; j++){
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	int ans = INT_MIN;
	for (int i = 0; i < n; i++) ans = max(ans, dp[i][n]);
	cout << ans << '\n';
	return 0;
}