#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10, MOD = 1e9+7;


vector<int> w, dp;

int main(){
	int n, x;
	cin >> n >> x;
	w.resize(n);
	dp.resize(N);
	for(int i = 0; i<n; i++) cin >> w[i];
	dp[0] = 1;
	for(int i = 0; i<n; i++){
		for(int j = w[i]; j<N; j++){
			dp[j] = (dp[j]+dp[j-w[i]])%MOD;
		}
	}
	cout << dp[x] << "\n";
	return 0;
}