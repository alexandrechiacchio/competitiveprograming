#include <bits/stdc++.h>
using namespace std;

int sqr_dist(int x, int y){
	return x*x+y*y;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int x, y, v, t;
		cin >> x >> y >> v >> t;
		if(sqr_dist(x, y) <= v*v*t*t) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}