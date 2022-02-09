#include <bits/stdc++.h>
using namespace std;


set<int> blue, red, mred, mblue;
vector<int> v;
int t, n;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--){
		bool ans = true;
		cin >> n;
		v.resize(n);
		red.clear();
		blue.clear();
		mred.clear();
		mblue.clear();
		for(int i = 1; i<=n; i++){
			mred.insert(i);
			mblue.insert(-i);
		}
		for(int i = 0; i<n; i++) cin >> v[i];
		for(int i = 0; i<n; i++){
			char c;
			cin >> c;
			if(c=='R'){
				if(red.count(v[i])){
					auto it = *mred.upper_bound(v[i]);
					if(it<=v[i]) {
						ans = false;
						continue;
					}
					red.insert(it);
					mred.erase(it);
				}
				else{
					red.insert(v[i]);
					mred.erase(v[i]);
				}
			}
			else {
				if(blue.count(-v[i])){
					int it = *mblue.upper_bound(-v[i]);
					if(it<=-v[i]) {
						ans = false;
						continue;
					}
					blue.insert(it);
					mblue.erase(it);
				}
				else{
					blue.insert(-v[i]);
					mblue.erase(-v[i]);
				}
			}
		}
		if(ans) cout << "YES\n";
		else cout << "NO\n"; 

	}
	return 0;
}