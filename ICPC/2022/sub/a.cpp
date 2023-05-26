#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(NULL);
	ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  string s; 
  cin >> s;
  int cnt = 0, ans = 0;
  for (int i = 0; i<n; i++){
    if(s[i] == 'a') cnt++;
    else {
      if(cnt > 1){
        ans += cnt;
      }
      cnt = 0;
    }
  }
  if(cnt>1) ans+= cnt;
  cout << ans << '\n';
  return 0;
}