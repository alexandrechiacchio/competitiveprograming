#include <bits/stdc++.h>
using namespace std;

int n, x, y;

int main (){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> x >> y;
	cout << max(__popcount(abs(x - (1<<n-1))), __popcount(abs(y - (1<<n-1)))) << '\n';
	return 0;
}