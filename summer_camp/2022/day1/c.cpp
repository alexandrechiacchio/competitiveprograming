#include <bits/stdc++.h>
using namespace std;


vector<int> v;
int n, c;

bool check(int u){
	int last = v[0], cnt = c-1;
	for(int i = 1; i<n and cnt; i++){
		if(v[i]-last>=u){
			last = v[i];
			cnt--;
		}
	}
	return !cnt;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> c;
		v.resize(n);
		for(int i = 0; i<n; i++) cin >> v[i];
		sort(v.begin(), v.end());
		int lo = 0, hi = 1e9;
		int mid = (lo+hi)/2;
		while(lo<hi){
			if(check(mid)) lo = mid+1;
			else hi = mid;
			mid = (lo+hi)/2;
		}
		cout << mid-1 << '\n';
	}
	return 0;
}