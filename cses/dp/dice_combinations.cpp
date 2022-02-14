#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7, N = 1e6+10;

vector<int> dp(N);

int _dp(int u){
	for(int i = 0; i<=u; i++){
		for(int j = 1; j<=6; j++){
			dp[j+i] = (dp[j+i]+dp[i])%MOD;
		}
	}
	return dp[u];
}

int main(){
	int n;
	cin >> n;
	dp[0] = 1;
	cout << _dp(n);
	return 0;
}