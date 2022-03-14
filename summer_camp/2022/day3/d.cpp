#include <bits/stdc++.h>
using namespace std;

long long x, y, r, n;



bool dist(pair<long long, long long> p) {
	return ((p.first * p.first + p.second * p.second) > (r * r));
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> x >> y >> r >> n;
	vector<pair<long long, long long>> above_points, below_points;
	for(int i = 0; i<n; i++){
		pair<long long ,long long> p;
		cin >> p.first >> p.second;
		p.first -= x;
		p.second -= y;
		if(dist(p)) continue;
		long long gcd = abs(__gcd(p.first, p.second));
		p.first /= gcd, p.second /= gcd;
		if(p.second < 0) below_points.push_back(p);
		else above_points.push_back(p);
	}
	sort(above_points.begin(), above_points.end());
	sort(below_points.begin(), below_points.end());
	above_points.erase(unique(above_points.begin(), above_points.end()), above_points.end());
	below_points.erase(unique(below_points.begin(), below_points.end()), below_points.end());
	cout << above_points.size()+below_points.size() << '\n';
	return 0;
}