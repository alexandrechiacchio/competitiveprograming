#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a, b, ans = 0;
		cin >> a >> b;
		if(a>b) swap(a,b);
		int x = (b-a)/2;
		x = min(a, x);
		b-=3*x;
		a-=x;
		ans += x;
		if(a>0 and b>0) ans += a/2;
		cout << ans << '\n';
	}
	return 0;
}