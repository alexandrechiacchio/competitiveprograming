#include <bits/stdc++.h>
using namespace std;

const int N = 5e4+5;

int n, m, t;
vector<int> tt(N, -1);
vector<bool> v(N+N);

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n >> m;
		int sz = 0;
		tt.clear();
		tt.resize(N, -1);
		v.clear();
		v.resize(N+N);
		for(int i = 1; i<=m; i++){
			int aux;
			cin >> aux;
			if(v[aux] == false and sz<n){
				tt[n-sz] = i;
				sz++;
				v[aux] = true;
			}
		}
		for(int i = 1; i<=n; i++) cout << tt[i] << ' ';
		cout << '\n';
	}
	return 0;
}