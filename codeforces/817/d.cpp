#include <bits/stdc++.h>
using namespace std;


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		long long n, val = 0;
		string s;
		cin >> n >> s;
		for(int i = 0; i<n; i++){
			if(s[i] == 'L') val += i;
			else val += n-i-1;
		}
		int k = 0;
		for(int i = 0; i<n/2; i++){
			if(s[i] == 'L'){
				k++;
				val -= i;
				val += n-i-1;
				cout << val << ' ';
			}
			if(s[n-i-1] == 'R'){
				k++;
				val += n-i-1;
				val -= i;
				cout << val << ' ';
			}
		}
		while(k < n) cout << val << ' ', k++;
		cout << '\n';
	}
	return 0;
}