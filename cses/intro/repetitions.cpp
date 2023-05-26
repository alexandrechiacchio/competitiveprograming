#include <bits/stdc++.h>
using namespace std;


int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  int ans = 1;
  int cnt = 1;
  for(int i = 1; i<s.size(); i++){
    if(s[i] == s[i-1]){
      cnt++;
      ans = max(ans, cnt);
    } else {
      cnt = 1;
    }
  }
  cout << ans << '\n';
  return 0;
}