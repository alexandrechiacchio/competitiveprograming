#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  vector<long long> v(n);
  for(int i = 0; i<n; i++) cin >> v[i];
  long long ans = 0;
  for(int i = 1; i<n; i++) if(v[i] < v[i-1]) ans += v[i-1] - v[i], v[i] = max(v[i], v[i-1]);
  cout << ans << '\n';
  return 0;
}