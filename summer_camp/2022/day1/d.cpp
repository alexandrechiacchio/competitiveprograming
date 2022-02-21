#include <bits/stdc++.h>
using namespace std;

double calc_v(vector<pair<int, int>> v){
	double out = 0;
	v.push_back(v[0]);
	for(int i = 0; i<v.size()-1; i++){
		out += v[i].first*v[i+1].second;
		out -= v[i].second*v[i+1].first;
	}
	return out/2;
}

int main(){
	freopen("in.txt", "r", stdin);
	// cin.tie(NULL);
	// ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<pair<int, int>> v(n);
		for(int i = 0; i<n; i++) cin >> v[i].first >> v[i].second;
		int w;
		cin >> w;
		const double volume = w*calc_v(v);
		double curr_volume, rain, consumption;
		cin >> curr_volume >> consumption >> rain;
		curr_volume*= volume/100.0;
		if(curr_volume<consumption){
			curr_volume = 0.0;
			cout << "Lack of water. ";
		} else {
			curr_volume-= consumption;
		}
		if(curr_volume+rain>volume){
			cout << "Excess of water. ";
			curr_volume = volume;
		} else {
			curr_volume+= rain;
		}
		cout << "Final percentage: " << (int)(curr_volume/volume*100.0) << "%\n";
		

	}

	return 0;
}