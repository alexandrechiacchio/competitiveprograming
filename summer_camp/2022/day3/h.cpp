#include <bits/stdc++.h>
using namespace std;

int n, last;
vector<pair<int, char>> ans;
vector<pair<int, int>> pieces;
vector<pair<int, int>> cur;
bool used[10];
bool solved;

bool check(pair<int, int> p){
	if(ans.size() == 0) return true;
	if(p.first == cur.back().second) return true;
	return false;
}

void bt(int pos = 0){
	if(solved) return;
	if(pos == n){
		solved = true;
		for(auto i: ans) cout << i.first << " " << i.second << '\n';
		return;
	}
	for(int i = 0; i<pieces.size(); i++){
		if(not used[i]){
			if(check({pieces[i].first, pieces[i].second})){
				ans.push_back({i+1, 'a'});
				cur.push_back({pieces[i].first, pieces[i].second});
				used[i] = true;
				bt(pos+1);
				ans.pop_back();
				cur.pop_back();
				used[i] = false;
			}
			if(check({pieces[i].second, pieces[i].first})){
				ans.push_back({i+1, 'b'});
				cur.push_back({pieces[i].second, pieces[i].first});
				used[i] = true;
				bt(pos+1);
				ans.pop_back();
				cur.pop_back();
				used[i] = false;
			}
		}
	}
}


int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	pieces.resize(n);
	for (int i = 0; i < n; i++) cin >> pieces[i].first >> pieces[i].second;
	bt();
	return 0;
}