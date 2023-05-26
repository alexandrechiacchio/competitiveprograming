#include <bits/stdc++.h>
using namespace std;


int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  vector<string> ans;
  do{
    ans.push_back(s);
  } while(next_permutation(s.begin(), s.end()));
  sort(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for (string i: ans) cout << i << '\n';
  return 0;
}