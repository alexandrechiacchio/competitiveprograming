#include <bits/stdc++.h>
using namespace std;


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int cntr = 0, cntb = 0, cntg = 0;
		bool ans = true;
		for(int i = 0; i<s.size(); i++){
			if(s[i]=='r') cntr++;
			else if(s[i]=='g') cntg++;
			else if(s[i]=='b') cntb++;
			else if(s[i]=='R' and not cntr) ans = false;
			else if(s[i]=='G' and not cntg) ans = false;
			else if(s[i]=='B' and not cntb) ans = false;
		}
		if(ans) cout << "YES\n";
		else cout << "NO\n";
	}
}