#include <bits/stdc++.h>
using namespace std;


int main(){
	int n, m;
	cin >> n >> m;
	multiset<int> s;
	for(int i = 0; i<n; i++){
		int a;
		cin >> a;
		s.insert(a);
	}
	for(int i = 0; i<m; i++){
		int a;
		cin >> a;
		auto it = s.upper_bound(a);
		if(it!=s.begin()) it--;
		if(*it <= a and s.size()){
			cout << *it << '\n';
			s.erase(it);
		}
		else cout << "-1\n";
	}
	return 0;
}