#include <bits/stdc++.h>
using namespace std;


int t, n;
set<int> s;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n;
		s.clear();
		for(int i = 0; i<n; i++){
			int a;
			cin >> a;
			s.insert(a);
		}
		int aux = s.size();
		for(int i = 1; i<=n; i++){
			if(i<aux) cout << aux << ' ';
			else cout << i << ' ';
		}
		cout << '\n';
	} 
	return 0;
}