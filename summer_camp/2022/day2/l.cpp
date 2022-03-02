#include <bits/stdc++.h>
using namespace std;

double n, h, area;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> h;
	area = h/2/n;
	cout << setprecision(12) << fixed;
	for(int i = 1; i<n; i++){
		cout << sqrt(2*h*area*i) << ' ';
	}
	cout << '\n';
	return 0;
}