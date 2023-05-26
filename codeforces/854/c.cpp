#include <bits/stdc++.h>
using namespace std;


int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		string a, b;
		multiset<char> ms;
		for(int i = 0; i<(int)s.size(); i++) ms.insert(s[i]);
		while(ms.size()){
			auto cur = ms.begin();
			cout << *next(cur) << '\n';
			cout << ms.count(*next(cur)) << " + " << 1 << " == " << ms.size() << "\n";
			if(ms.count(*cur) > 1){
				a += *cur;
				cur++;
				b+= *cur;
				ms.erase(cur++);
				ms.erase(ms.begin());
			} else if(ms.count(*next(cur)) + 1 == ms.size()){
				cur++;
				int aux = ms.count(*cur);
				for(int i = 0; i<(aux+1)/2; i++){
					a += *cur;
					ms.erase(cur++);
				}
				cur = ms.begin();
				a += *cur;
				ms.erase(cur++);
				cur++;
				for(int i = 0; i<aux/2; i++){
					a += *cur;
					ms.erase(cur++);
				}
			} else {
				cur++;
				while(ms.size()>1){
					a+= *cur;
					ms.erase(cur++);
				}
				cur = ms.begin();
				a += *cur;
				ms.clear();
			}

		}
		string ans = a + b;
		cout << ans << '\n';
	}
	return 0;
}