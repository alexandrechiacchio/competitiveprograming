#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

//dp [i][j] = resp p/ retang ixj
//dp[i][j] 

int main() {
	int a, b;
	cin >> a >> b;
	int dp[600][600];
	for (int i = 1; i < 600; i++) fill(dp[i] + 1, dp[i] + 600, INF);
	for(int i = 0; i < 600; i++) dp[i][i] = 0;
	for (int i = 1; i <= a; i++) for (int j = 1; j <= b; j++) {
		for (int k = 1; k < i; k++) {
			dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
		}
		for (int k = 1; k < j; k++) {
			dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k] + 1);
		}
	}
	cout << dp[a][b] << '\n';
}