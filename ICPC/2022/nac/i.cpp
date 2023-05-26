#include <bits/stdc++.h>
using namespace std;


int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  
  int r, c;
  cin >> r >> c;
  vector<vector<int>> v(r+10, vector<int>(c+10, -1e8));
  vector<vector<int>> _vis(r+10, vector<int>(c+10));
  vector<pair<int, int>> p(r*c + 10);
  for(int i = 1; i<=r; i++) for(int j = 1; j<=c; j++){
    cin >> v[i][j];
    p[v[i][j]] = {i, j};
  }
  int ans = 0;
  for(int i = 1; i<=r*c; i++){
    priority_queue<int> pq;
    pq.push(-i);
    int cnt = 0;
    int cur_min = i;
    vector<vector<int>> vis = _vis;
    int lin = p[i].first, col = p[i].second;
    vis[lin][col] = 1;
    while(!pq.empty()){
      pq.pop();
      if(v[lin-1][col] > v[lin][col] && vis[lin-1][col] == 0){
        pq.push(-v[lin-1][col]);
        vis[lin-1][col] = 1;
      }
      if(v[lin+1][col] > v[lin][col] && vis[lin+1][col] == 0){
        pq.push(-v[lin+1][col]);
        vis[lin+1][col] = 1;
      }
      if(v[lin][col-1] > v[lin][col] && vis[lin][col-1] == 0){
        pq.push(-v[lin][col-1]);
        vis[lin][col-1] = 1;
      }
      if(v[lin][col+1] > v[lin][col] && vis[lin][col+1] == 0){
        pq.push(-v[lin][col+1]);
        vis[lin][col+1] = 1;
      }
      cur_min = -pq.top();
      lin = p[cur_min].first;
      col = p[cur_min].second;
      cnt++;
    } 
    ans = max(cnt, ans);
  }
  cout << ans << '\n';
  return 0;
}