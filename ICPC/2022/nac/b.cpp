#include <bits/stdc++.h>
using namespace std;


int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  vector<pair<int, int>> token(t);
  vector<bool> vis(t);
  for(int i = 0; i<t; i++) cin >> token[i].first >> token[i].second;
  int p;
  cin >> p;
  vector<pair<int, int>> card(p);
  vector<vector<int>> ans(p);
  for(int i = 0; i<p; i++){
    cin >> card[i].first >> card[i].second;
    for(int j = 0; j<t; j++){
      if(token[j].second < card[i].first*token[j].first + card[i].second and not vis[j]){
        vis[j] = true;
        ans[i].push_back(j+1);
      }
    }
  }
  for(int i = 0; i<p; i++){
    cout << ans[i].size() << " ";
    for(auto j = ans[i].begin(); j!=ans[i].end(); j++) cout << *j << " ";
    cout << '\n';
  }
  return 0;
}