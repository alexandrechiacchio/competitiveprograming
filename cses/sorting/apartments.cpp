#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

int v[N], w[N];


int main(){
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i<n; i++) cin >> v[i];
	for(int i = 0; i<m; i++) cin >> w[i];
	sort(v, v+n);
	sort(w, w+m);
	int l, r, ans;
	l = r = ans = 0;
	while(l<n and r<m){
		if(v[l]>w[r]+k){
			r++;
		} else if(v[l]<w[r]-k){
			l++;
		} else {
			ans++;
			r++;
			l++;
		}
	}
	cout << ans << '\n';
	return 0;
}
