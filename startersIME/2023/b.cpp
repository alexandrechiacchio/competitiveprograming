#include <bits/stdc++.h>
using namespace std;


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		double x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		double a = (y1*x2-y2*x1)/(x1*x2*(x1-x2));
		double b = (y1-a*x1*x1)/x1;
		cout << setprecision(10) << fixed << -b/a << '\n';
	}
	return 0;
}