#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e6, MOD = 1e9+7;
 
vector<int> coins, dp(N+10);
 
int _dp(int u){
	for(int i = 0; i<=u; i++){
		for(int j = 0; j<coins.size(); j++){
			if(i+coins[j]<=N) dp[i+coins[j]] = (dp[i]+dp[i+coins[j]])%MOD;
		}
	}
	return dp[u];
}
 
int main(){
	int n, x;
	cin >> n >> x;
	coins.resize(n);
	for(int i = 0; i<n; i++) cin >> coins[i];
	dp[0] = 1;
	cout << _dp(x) << '\n';
	return 0;
}