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
		vector<int> a(n);
		int even_cnt = 0, odd_cnt = 0;
		for(int i = 0; i<n; i++){
			cin >> a[i];
			if(a[i]&1) odd_cnt++;
			else even_cnt++;
		}
		//changing everything to odd
		//the smallest element cant be even
		if(odd_cnt){
			if(*min_element(a.begin(), a.end()) & 1) cout << "YES\n";
			else cout << "NO\n";	
		} else {
			cout << "YES\n";
		}
	}
	return 0;
}