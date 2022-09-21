#include <bits/stdc++.h>
using namespace std;


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string s, w, ans;
	cin >> s;
	w = s;
	ans.resize(s.size(), '0');
	for(int i = 0; i<s.size(); i++) for(int j = i+1; j<s.size(); j++){
		swap(s[i], s[j]);
		if(s[0] != '0' and s<w and s>ans){
			ans = s;
			break;
		}
		swap(s[i], s[i+1]);
	}
	if(ans != s) cout << ans << '\n';
	else cout << "-1\n";
	return 0;
}