#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main(){
	int n;
	cin >> n;
	vector<string> v(n+1);
	vector<vector<int>> dp(n+10, vector<int>(n+10));
	for(int i = 1; i<=n; i++){
		v[i] += '.';
		string s;
		cin >> s;
		v[i] += s;
	}
	dp[0][1] = 1;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			if(v[i][j]!='*') dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
		}
	}
	cout << dp[n][n] << '\n';
	return 0;
}