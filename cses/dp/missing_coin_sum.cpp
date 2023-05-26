#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5, M = 1e6;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i<n; i++) cin >> v[i];
	bool b[N];
	memset(b, false, sizeof b);
	b[0] = true;
	for(int i = 0; i<n; i++){
		for(int j = M; j>=v[i]; j--){
			if(b[j-v[i]]) b[j] = true;
		}
	}
	for(int i = 0; i<M; i++) if(!b[i]){
		cout << i << '\n';
		return 0;
	}
	return 0;
}