#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 1e6+6; 
int n, t;

// F(i+1) = 2*(F(i) + C(i))

// C(i) = 2*C(i)

vector<long long> a(N);
vector<long long> b(N);

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	a[1] = 1;
	b[1] = 1;
	for (int i = 1; i<N-1; i++){
		a[i+1] = (2*a[i] + b[i])%MOD;
		b[i+1] = (4*b[i] + a[i])%MOD;
		// cout << i << " " << a[i] + b[i];
	}
	cin >> t;
	while(t--){
		cin >> n;
		cout << (((a[n]+b[n])%MOD)+MOD)%MOD << '\n';
	}
	return 0;
}