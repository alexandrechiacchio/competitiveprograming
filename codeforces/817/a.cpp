#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		int n;
		cin >> n >> s;
		if(n!=5){
			cout << "NO\n";
		} else {
			bool f[5];
			memset(f, 0, sizeof f);
			for(int i = 0; i<5; i++){
				if(s[i] == 'T'){
					if(f[0]) break;
					else f[0] = true;
				} else if(s[i] == 'i'){
					if(f[1]) break;
					else f[1] = true;
				} else if(s[i] == 'm'){
					if(f[2]) break;
					else f[2] = true;
				} else if(s[i] == 'u'){
					if(f[3]) break;
					else f[3] = true;
				} else if(s[i] == 'r'){
					if(f[4]) break;
					else f[4] = true;
				} else break;
			}
			if(f[0] & f[1] & f[2] & f[3] & f[4]) cout << "YES\n";
			else cout << "NO\n";
		}

	}
	return 0;
}