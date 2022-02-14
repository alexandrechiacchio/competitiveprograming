#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+6, INF = 0x3f3f3f3f;

vector<int> coins, dp(N, INF);


void _dp(int u){
	for(int i = 1; i<=u; i++){
		for(int j = 0; j<coins.size(); j++){
			if(i>=coins[j]){
				dp[i] = min(dp[i], dp[i-coins[j]] + 1);
			}
		}
	}
}

int main(){
	int n, x;
	cin >> n >> x;
	coins.resize(n);
	for(int i = 0; i<n; i++) cin >> coins[i];
	dp[0] = 0;
	_dp(x);
	if(dp[x]!=INF) cout << dp[x] << '\n';
	else cout << "-1\n";
	return 0;
}