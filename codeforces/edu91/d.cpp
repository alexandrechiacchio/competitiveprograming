#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("in.txt", "r", stdin);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	long long n, m, x, y, k;
	cin >> n >> m >> x >> k >> y;
	vector<long long> a(n+10), b(m+10);
	for(long long i = 1; i<=n; i++) cin >> a[i];
	for(long long i = 1; i<=m; i++) cin >> b[i];
	long long pos1 = 1, pos2 = 1;
	vector<bool> c(n+10);
	while(pos2<=m){
		while (a[pos1]!=b[pos2] and pos1<=n){
			c[pos1] = true;
			pos1++;
		}
		if(pos1==n+1){
			cout << "-1\n";
			return 0;
		}
		pos1++;
		pos2++;
		if(pos2==m+1) while(pos1<=n) {
			c[pos1] = true;
			pos1++;
		}
	}
	pos1 = pos2 = 1;
	long long ans = 0, maxx;
	while(pos1<=n){
		pos1 = pos2;
		while(not c[pos1] and pos1<=n)pos1++;
		if(pos1==n+1)break;
		pos2 = pos1+1;
		maxx = a[pos1];
		while(c[pos2] and pos2<=n){
			maxx = max(maxx, a[pos2]);
			pos2++;
			
		}
		long long range = pos2-pos1;
		if(range<k and not(a[pos1-1]>maxx or a[pos2]>maxx)){
			cout << "-1\n";
			return 0;
		}
		if(range%k) ans+= y*(range%k);
		range-= range%k;
		if(k*y>=x) ans+= x*(range/k);
		else {
			ans+= (range-k)*y;
			if(a[pos1-1]>maxx or a[pos2]>maxx) ans+= k*y;
			else ans+= x;
		}
	}
	cout << ans << '\n';
	return 0;
}