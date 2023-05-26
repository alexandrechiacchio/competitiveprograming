#include <bits/stdc++.h>
using namespace std;


long long fun(long long u){
	return 10*(u)*u/2;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while(q--){
		int k;
		cin >> k;
		long long lo = 0;
		long long hi = INT_MAX-1;
		long long mid;
		while(lo<hi){
			mid = (lo+hi)/2;
			if(fun(mid) < k) lo = mid+1;
			else hi = mid;
		}
		cout << mid << '\n';
	}
	return 0;
}