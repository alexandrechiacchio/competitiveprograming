#include <bits/stdc++.h>
using namespace std;

 
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> p(n);
		for(int i = 0; i<n; i++) cin >> p[i];
		int ans = 1, maxx = p[0];
		set<int> old_maxx;
		for(int i = 1; i<n; i++){
			if(p[i]>maxx){
				old_maxx.insert(maxx);
				maxx = p[i];
				ans++;
			}
			while(old_maxx.lower_bound(p[i])!=old_maxx.end()){
				ans--;
				old_maxx.erase(old_maxx.lower_bound(p[i]));
			}
		}
		cout << ans << '\n';
	}
	return 0;
}