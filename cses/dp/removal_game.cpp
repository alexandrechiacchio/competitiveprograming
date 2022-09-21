#include <bits/stdc++.h>
using namespace std;


int dp[5010][5010];

//dp[i] = maior pontuação com i = lo e j = hi
//dp[i+2][j] = max(dp[i+2][j], dp[i][j] + v[i]);
//dp[i+1][j+1] = max({dp[i+1][j+1], dp[i][j] + v[i], dp[i][j] + v[j]});
//dp[i][j+2] = max(dp[i][j+2], dp[i][j] + v[j]);

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	for(int i = 1; i <= n; i++) for(int j = 0; j+i < n; j++){
		dp[i][j] = max(dp[j+1][j+i] + v[i], dp[j][j+i-1] + v[j]);
	}
	cout << '\n';
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cout << dp[i][j] << " ";
		}
		cout << '\n';
	}
	int ans = INT_MIN;
	for(int i = 0; i<n; i++) ans = max(ans, dp[i][i]);
	cout << ans << '\n';
	return 0;
}