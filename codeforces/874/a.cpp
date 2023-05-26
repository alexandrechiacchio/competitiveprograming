#include <bits/stdc++.h>
using namespace std;


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string aux;
		cin >> aux;
		set<string> s;
		for(int j = 0; j<n-1; j++){
			s.insert(aux.substr(j, 2));
		}
		cout << s.size() << '\n';
	}
	return 0;
}