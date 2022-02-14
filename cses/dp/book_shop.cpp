#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

vector<int> dp(N);

int main(){
	int n, x;
	cin >> n >> x;
	vector<int> w(n), v(n);
	for(int i = 0; i<n; i++) cin >> w[i];
	for(int i = 0; i<n; i++) cin >> v[i];
	for(int i = 0; i<n; i++){
		
		for(int j = N-1; j>=w[i]; j--){
			dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
		}
	}
	cout << dp[x] << '\n';
	return 0;
}