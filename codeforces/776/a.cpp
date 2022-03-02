#include <bits/stdc++.h>
using namespace std;


int t;
pair<int, int> p[3];

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout << setprecision(12) << fixed;
	cin >> t;
	while(t--){
		for(int i = 0; i<3; i++){
			cin >> p[i].first >> p[i].second;
		}
		if(p[0].second==p[1].second and p[2].second<p[0].second){
			cout << abs(p[0].first-p[1].first) << '\n';
		} else if(p[0].second==p[2].second and p[1].second<p[0].second){
			cout << abs(p[0].first-p[2].first) << '\n';
		} else if(p[2].second==p[1].second and p[0].second<p[2].second){
			cout << abs(p[2].first-p[1].first) << '\n';
		} else {
			cout << 0 << '\n';
		}
	}
	return 0;
}