#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int cnt_a = 0, cnt_b = 0, cnt_c = 0;
		for(char i: s){
			if(i=='A') cnt_a++;
			else if(i=='B') cnt_b++;
			else cnt_c++;
		}
		if(cnt_b == cnt_a+cnt_c) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}