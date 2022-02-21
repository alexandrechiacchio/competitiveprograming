#include <bits/stdc++.h>
using namespace std;


int main(){
	int n, x;
	cin >> n >> x;
	multiset<int> s;
	for(int i = 0; i<n; i++){
		int a;
		cin >> a;
		s.insert(a);
	}
	int ans = 0;
	while(not s.empty()){
		ans++;
		int a = *s.rbegin();
		s.erase(s.find(a));
		auto it = s.upper_bound(x-a);
		if(it!=s.begin()) it--;
		int b = *it;
		if(a+b<=x and s.size()>0){
			s.erase(s.find(b));
		}
	}
	cout << ans << '\n';
	return 0;
}