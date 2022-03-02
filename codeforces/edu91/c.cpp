#include <bits/stdc++.h>
using namespace std;

bool comp(int u, int v) {return u>v;}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n, x;
		cin >> n >> x;
		vector<int> v(n);
		for(int i = 0; i<n; i++) cin >> v[i];
		sort(v.begin(), v.end(), comp);
		int ans = 0, last = -1;
		for(int i = 0; i<n; i++){
			if(v[i]*(i-last)>=x){
				ans++;
				last = i;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}