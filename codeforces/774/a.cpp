#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	long long n, s, t;
	cin >> t;
	while(t--){
		cin >> n >> s;
		cout << s/n/n << '\n';
	}
	return 0;
}