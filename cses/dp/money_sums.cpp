#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i<n; i++) cin >> v[i];
	bool dp[N];
	memset(dp, 0, sizeof dp);
	dp[0] = 1;
	for(int i = 0; i<v.size(); i++){
		for(int j = N-1; j>=v[i]; j--){
			dp[j] |= dp[j-v[i]];
		}
	}
	vector<int> ans;
	for(int i = 1; i<N; i++) if(dp[i]){
		ans.push_back(i);
	}
	cout << ans.size() << '\n';
	for(int i: ans) cout << i << " ";
	cout << '\n';
	return 0;
}