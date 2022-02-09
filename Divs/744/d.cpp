#include <bits/stdc++.h>
using namespace std;


const int N = 2e5+5;

int t, n, a[N];
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> ans;

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		ans.clear();
		while(not pq.empty()) pq.pop();
		for(int i = 0; i<n; i++){
			cin >> a[i];
			if(a[i]>0)pq.push({a[i], i});
		}
		while(pq.size()>1){
			pair<int, int> u = pq.top();
			pq.pop();
			pair<int, int> v = pq.top();
			pq.pop();
			if(u.first-v.first>0)pq.push({u.first-v.first, u.second});
			for(int i = 0; i<v.first; i++) ans.push_back({u.second+1, v.second+1});
		}
		cout << ans.size() << "\n";
		for(pair<int, int> i: ans) cout << i.first << " " << i.second << "\n";
	}
	return 0;
}