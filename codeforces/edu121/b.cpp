#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		bool f = false;
		string s, t;
		cin >> s;
		for(int i = s.size()-1; i>0; i--){
			if(s[i-1]+s[i]-'0'-'0'>=10){
				int aux = s[i-1]+s[i]-'0'-'0';
				s[i] = (aux%10)+'0';
				s[i-1] = (aux/10)+'0';
				f = true;
				cout << s << '\n';
				break;
			}
		}
		if(f) continue;
		t.resize(s.size()-1);
		t[0] = s[0]+s[1]-'0';
		t+= s.substr(2, s.size()-2);
		cout << t << '\n';
	}
	return 0;
}