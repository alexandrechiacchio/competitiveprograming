#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

long long find_cost(vector<int> &v, int k){
	long long cost = 0;
	for(int i = 0; i<v.size(); i++) cost += abs(v[i] - k);
	return cost;
}

bool check(vector<int> &v, int k){
	long long cost1 = find_cost(v, k);
	long long cost2 = find_cost(v, k+1);
	return cost1 > cost2;
}

int b_search(vector<int> &v){
	int lo = 1, hi = INF;
	int mid = (lo+hi)/2;
	while(lo<hi){
		//cout << lo << " " << mid << " " << hi << '\n';
		if(check(v, mid)) lo = mid+1;
		else hi = mid;
		mid = (lo+hi)/2;
	}
	return mid;
}

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i<n; i++) cin >> v[i];
	cout << find_cost(v, b_search(v)) << '\n';
	return 0;
}