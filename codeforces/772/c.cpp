#include <bits/stdc++.h>
using namespace std;
 
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	long long t;
	cin >> t;
	while(t--){
		long long n;
		cin >> n;
		vector<long long> v(n);
		for(long long i = 0; i<n; i++) cin >> v[i];
		long long diff = v[n-2]-v[n-1];
		bool f = v[n-2]<=v[n-1];
		vector<vector<int>> ans;
		for(long long i = n-3; i>=0 and f; i--){
			if(v[i]>v[i+1] and diff<=v[i+1]){
				v[i] = diff;
				vector<int> aux = {i+1, i+2, n};
				ans.push_back(aux);
			} else if(v[i]>v[i+1] and diff>v[i+1]){
				f = false;
			}
			diff = v[i]-v[n-1];
		}
		if(f){
			cout << ans.size() << '\n';
			for(auto i: ans) cout << i[0] << " " << i[1] << " " << i[2] << '\n';
		} else {
			cout << "-1\n";
		}
	}
	return 0;
}