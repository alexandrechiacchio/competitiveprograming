#include <bits/stdc++.h>
using namespace std;

long long t, a, b, c;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> a >> b >> c;
		cout << a+b+c-1 << '\n';
	}
	return 0;
}