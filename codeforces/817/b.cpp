#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		string s, w;
		cin >> n >> s >> w;
		bool f = true;
		for(int i = 0; i<n; i++){
			if((s[i] == 'R' and w[i]!='R') or (s[i] != 'R' and w[i] == 'R')){
				f = false;
			}
		}
		if(f) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}