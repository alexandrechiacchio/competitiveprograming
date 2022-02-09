#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> v(n), w, ans1, ans2;
		for(int i = 0; i<n; i++) cin >> v[i];
		w = v;
		if(v[0]!=n and v[v.size()-1]!=n){
			cout << "-1\n";
			continue;
		}
		reverse(w.begin(), w.end());
		while(ans1.size()+ans2.size()<n){
			if(w[w.size()-1] > v[v.size()-1]){
				ans1.push_back(w[w.size()-1]);
				w.pop_back();
			} else {
				ans2.push_back(v[v.size()-1]);
				v.pop_back();
			}
		}
		reverse(ans1.begin(), ans1.end());
		for(int i: ans1) cout << i << " ";
		for(int i: ans2) cout << i << " ";
		cout << "\n";
	}
}