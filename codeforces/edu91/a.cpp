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
		vector<int> v(n);
		set<pair<int, int>> s;
		bool f = false;
		int a, b, c;
		a = b = c = 0;
		for(int i = 0; i<n; i++){
			cin >> v[i];
			if(v[i]==1) a = i;
		}
		for(int i = 0; i<a; i++) {
			s.insert({v[i], i});
			pair<int, int> p = *s.begin();
			if(v[i]>p.first){
				c = a;
				a = p.second;
				b = i;
				f = true;
				break;
			}
		}
		s.clear();
		for(int i = a; i<n; i++) {
			s.insert({v[i], i});
			pair<int, int> p = *s.rbegin();
			if(v[i]<p.first){
				c = i;
				b = p.second;
				f = true;
				break;
			}
		}
		if(f) cout << "YES\n" << a+1 << " " << b+1 << " " << c+1 << "\n";
		else cout << "NO\n";

		
	}
	return 0;
}