#include <bits/stdc++.h>
using namespace std;

int t, n;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--){
		// cin >> n;
		cin >> n;
		if(n<=5){
			cout << "-1\n";
		} else {
			if(n&1){
				cout << 3 << " " << n-3 << '\n';
			} else {
				cout << 2 << " " << n-2 << '\n';
			}
		}
	}
	return 0;
}