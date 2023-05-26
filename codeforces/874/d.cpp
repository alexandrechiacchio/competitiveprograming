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
		vector<int> p(n);
		for(int i = 0; i<n; i++)
			cin >> p[i];
		set<vector<int>> s;
		auto r_it = max_element(p.begin(), p.end()); 
		if(r_it == p.begin()) r_it = max_element(p.begin() + 1, p.end());
		int r = r_it - p.begin();
		int l;
		for(int i = r-1; i>0; i--) if(p[i-1] > p[i]){
			l = i;
			break;
		}
		cout << l << " " << r << '\n';
		// vector<int> ans(n);
		// for(int i = 0; i<n; i++){
		// 	if(i<n-r) ans[i] = p[i+r]; // ok
		// 	else if(i < n - l) ans[i] = p[r-1 - (i-(r-n))];
		// 	else ans[i] = p[i-(n-l)];
		// }
		// for(int i: ans) cout << i << " ";
		// cout << '\n';
	}
	return 0;
}