#include <bits/stdc++.h>
using namespace std;


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<long long> p(n+1);
	for(int i = 1; i<=n; i++){
		cin >> p[i];
		p[i] += p[i-1];
	}
	int m;
	cin >> m;
	for(int i = 0; i<m; i++){
		long long a;
		cin >> a;
		auto it = lower_bound(p.begin(), p.end(), a);
		cout << *it << " " << it-p.begin() << '\n';
	}
	return 0;
}