#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int q; cin >> q;
	while(q--){
		long long n; cin >> n;
		n--;
		long long i = 1, p = 1;
		while(n){
			if(n - i*9*p < 0) break;
			n -= i*9*p;
			p *= 10;
			i++;
		}
		p += n/i;
		n = n%i;
		string s = to_string(p);
		cout << s[n] << '\n';
	}
	return 0;
}