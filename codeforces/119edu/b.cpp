#include <bits/stdc++.h>
using namespace std;


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	long long t;
	cin >> t;
	while(t--){
		long long w, h;
		cin >> w >> h;
		long long k;
		cin >> k;
		vector<long long> x0(k);
		for(long long i = 0; i<k; i++) cin >> x0[i];
		cin >> k;
		vector<long long> xh(k);
		for(long long i = 0; i<k; i++) cin >> xh[i];
		cin >> k;
		vector<long long> y0(k);
		for(long long i = 0; i<k; i++) cin >> y0[i];
		cin >> k;
		vector<long long> yw(k);
		for(long long i = 0; i<k; i++) cin >> yw[i];
		long long base_x = max(x0[x0.size()-1]-x0[0], xh[xh.size()-1]-xh[0]);
		long long base_y = max(y0[y0.size()-1]-y0[0], yw[yw.size()-1]-yw[0]);
		cout << max(base_x*h, base_y*w) << "\n";
	}
	return 0;
}