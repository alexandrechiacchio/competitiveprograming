#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	int n;
	cin >> n;

	long long ans = -INF, maxsofar = -INF, sum = 0;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		sum += a;
		if(sum > maxsofar) maxsofar = sum;
		ans = max(maxsofar, ans);
		if(sum < 0) sum = 0;
	}
	cout << ans << '\n';
	return 0;
}