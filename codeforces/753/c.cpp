#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> v;
		v.resize(n);
		for(int i = 0; i<n; i++){
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int min = INT_MIN, sum = 0;
		for(int i = 0; i<n; i++){
			if((v[i]-sum)>min) min = v[i]-sum;
			sum += v[i]-sum;
		}
		cout << min << '\n';
	}
	return 0;
}