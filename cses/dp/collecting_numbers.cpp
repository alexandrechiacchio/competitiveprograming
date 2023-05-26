#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int main(){
	int n;
	cin >> n;
	vector<int> ind(n+1), v(n+1);
	for(int i = 0; i<n; i++){
		cin >> v[i];
		ind[v[i]] = i;
	}
	for(int i = 0; i<=n; i++) cout << ind[i] << ' ';
	cout << '\n';
	int ans = 0;
	for(int i = 0; i<n; i++){
		if(v[i]<n){
			if(ind[v[i]]>ind[v[i+1]]) ans++, cout << i << '\n';
		}
	}
	cout << ans+1 << '\n';
}