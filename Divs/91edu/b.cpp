#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string s, ans;
		cin >> s;
		ans = s;
		int cr, cp, cs;
		cp = cr = cs = 0;
		int n = s.size();
		for(int i = 0; i<n; i++){
			if(s[i]=='R') cr++;
			else if(s[i]=='P') cp++;
			else cs++;
		}
		if(cp>=cr and cp>=cs) for(int i = 0; i<n; i++) ans[i] = 'S';
		if(cr>=cp and cr>=cs) for(int i = 0; i<n; i++) ans[i] = 'P';
		if(cs>=cr and cs>=cp) for(int i = 0; i<n; i++) ans[i] = 'R';
		cout << ans << '\n';
	}
}