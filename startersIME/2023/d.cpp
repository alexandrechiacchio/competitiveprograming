#include <bits/stdc++.h>
using namespace std;


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string s, t;
		cin >> s >> t;
		s += t;
		sort(s.begin(), s.end());
		cout << s << '\n';
	}
	return 0;
}