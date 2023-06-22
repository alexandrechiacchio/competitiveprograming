#include <bits/stdc++.h>
using namespace std;


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> x(n);
		for(int i = 0; i<n; i++) cin >> x[i];
		sort(x.begin(), x.end());
		pair<int, int> ans = {0, 0};
		for(int i = 0, sum = 0; i<n; i++){
			if(x[i] > sum){
				sum+= x[i];
				ans.first++;
				ans.second += x[i];
			}
		}
		cout << ans.first << " " << ans.second << '\n';
	}
	return 0;
}