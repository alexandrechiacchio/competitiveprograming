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
		vector<string> v(n-2);
		for(int i = 0; i<n-2; i++) cin >> v[i];
		string ans;
		ans += v[0];
		for(int i = 0; i<n-3; i++){
			if(v[i][1]!=v[i+1][0]) ans += v[i+1];
			else ans += v[i+1][1];
		}
		if(ans.size()<n) ans += 'a';
		cout << ans << "\n";
	}
	return 0;
}