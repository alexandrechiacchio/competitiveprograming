#include <bits/stdc++.h>
using namespace std;


bool comp(pair<int, int> u, pair<int, int> v){
	return u>v;
}

int main(){
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for(int i = 0; i<n; i++) cin >> v[i].first >> v[i].second;
	vector<pair<int, int>> w = v;
	vector<int> aux(n);
	sort(v.begin(), v.end());
	sort(w.begin(), w.end(), comp);
	for(int i = 0; i<n; i++){
		
	}
	return 0;
}