#include <bits/stdc++.h>
using namespace std;



int main(){
	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	for(int i = 0; i<n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	for(int i = 0; i<n/2; i++){
		int a = v[i];
		auto it = lower_bound(v.begin(), v.end(), x-a);
		if((&v[i] != it) and (a+*it == x)){
			cout << i << it;
		}
	}
	cout << "-1\n";
	return 0;
}