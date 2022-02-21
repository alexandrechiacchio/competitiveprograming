#include <bits/stdc++.h>
using namespace std;


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n, ans = 0;
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i<n; i++) cin >> v[i];
		for(int i = 1; i<n-1; i++) {
			if(v[i-1]<v[i] and v[i]>v[i+1]){
				v[i+1] = v[i];
				if(i<n-3) v[i+1] = max(v[i+2], v[i]);
				ans++;
			}
		}
		cout << ans << '\n';
		for(int i = 0; i<n; i++) cout << v[i] << " ";
		cout << '\n';
	}

	return 0;
}