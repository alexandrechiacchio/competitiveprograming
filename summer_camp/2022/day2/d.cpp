#include <bits/stdc++.h>
using namespace std;

int t, n, x, y;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n >> x >> y;
		for(int i = 1; x*i<=n; i++){
			if(x*i%y!=0){
				cout << x*i << " ";
			}
		}
		cout << '\n';
	}
	return 0;
}