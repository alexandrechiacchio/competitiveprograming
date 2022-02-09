#include <bits/stdc++.h>
using namespace std;


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		vector<int> b(7), a(3);
		for(int i = 0; i<7; i++) cin >> b[i];
		a[0] = b[0];
		a[1] = b[1];
		if(b[2] == b[0]+b[1]) a[2] = b[3];
		else a[2] = b[2];
		for(int i = 0; i<3; i++) cout << a[i] << " ";
		cout << '\n';
	}
	return 0;
}