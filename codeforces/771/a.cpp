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
		int p[n];
		for(int i = 0; i<n; i++) cin >> p[i];
		int pos = 0;
		while(p[pos]==pos+1) pos++;
		if(pos<n){
			int pos2 = pos+1;
			while(p[pos2]!=pos+1) pos2++;
			reverse(p + pos, p+pos2+1);
		}
		for(int i = 0; i<n; i++) cout << p[i] << " ";
		cout << '\n';
	}
	return 0;
}