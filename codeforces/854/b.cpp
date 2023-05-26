#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+3;

int n, t;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n;
    vector<pair<int, int>> a(n);
		for(int i = 0; i<n; i++){
      cin >> a[i].first;
      a[i].second = i+1;
    }
    int cnt = 0;
    for(int i = 0; i<n; i++) if(a[i].first == 1) cnt++;
    if(cnt != 0 and cnt!=n){cout << "-1\n"; continue;}
    vector<pair<int, int>> ans;
    sort(a.begin(), a.end());
    while(a.back().first != 2){
      int pos = n-1;
      while(pos >= 0 and a[pos].first == a[n-1].first) pos--;
      if(pos == -1) break;
      ans.push_back({a[n-1].second, a[pos].second});
      pair<int, int> aux = {a[n-1].first/a[pos].first, a[n-1].second};
      if(a[n-1].first % a[pos].first != 0) aux.first++;
      a.pop_back();
      a.emplace(lower_bound(a.begin(), a.end(), aux), aux);
    }
    cout << ans.size() << "\n";
    for(int i = 0; i<(int)ans.size(); i++) cout << ans[i].first << " " << ans[i].second << "\n";
    // for(int i = 0; i<n; i++) cout << a[i].first << " ";
    // cout << '\n';
	}
	return 0;
}