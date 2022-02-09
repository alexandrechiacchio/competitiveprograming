#include <bits/stdc++.h>
using namespace std;

char keyboard[26], s[60];

int find(char c){
	for(int i = 0; i<26; i++) if(c==keyboard[i]) return i;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> keyboard >> s;
		int ans = 0;
		for(int i = 0; i<strlen(s)-1; i++){
			ans += abs(find(s[i+1])-find(s[i]));
		}
		cout << ans << '\n';
	}
	return 0;
}
