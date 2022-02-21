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
		vector<long long> v(n);
		for(int i = 0; i<n; i++) cin >> v[i];
		for(int i = 0; i<n-1; i++){
			for(int j = i+1; j<n; j++){
				for(int k = 0; k<=30; k++){
					if((v[i] & (1 << k)) and (v[j] & (1<<k))){
						v[i] = v[i]^(1<<k);
					}
				}
			}
		}
		long long ans = 0;
		for(int i = 0; i<n; i++){
			ans += v[i];
		}
		cout << ans << '\n';
	}
	return 0;
}
