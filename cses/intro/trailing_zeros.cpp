#include <bits/stdc++.h>
using namespace std;


int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int fivePow = 5;
  int ans = 0;
  while(fivePow <= n){
    ans += n/fivePow;
    fivePow *= 5;
  }
  cout << ans << '\n';
  return 0;
}