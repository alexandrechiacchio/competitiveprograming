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
		if(not ((s[s.size()-1]-'0')&1)) cout << "0\n";
		else if(not ((s[0]-'0')&1)) cout << "1\n";
		else {
			bool f = false;
			for(int i = 1; i<s.size(); i++){
				if(not ((s[i]-'0')&1)){
					f = true;
					break;
				}
			}
			if(f) cout << "2\n";
			else cout << "-1\n";
		}
	}
	return 0;
}