#include <bits/stdc++.h>
using namespace std;

int t, n, k;




int main(){
	// cin.tie(NULL);
	// ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n >> k;
		int counter = 0;
		if(k>(n/2+(n%2))) cout << "-1\n";
		else {
			for(int i = 0; i<n; i++){
				for(int j = 0; j<n; j++){
					if(i%2 == 0 and j==i and counter<k){
						cout << 'R';
						counter++;
					}
					else cout << '.';
				}
				cout << '\n';
			}
		}
	}
	return 0;
}