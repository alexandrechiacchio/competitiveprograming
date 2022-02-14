#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 1; i<n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	for(int i = 1; i<=n; i++) if(v[i]!=i){
		cout << i << '\n';
		break;
	}
	return 0;
}