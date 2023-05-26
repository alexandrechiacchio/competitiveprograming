#include <bits/stdc++.h>
using namespace std;

long long toGray(long long u){
  return u^(u>>1);
}

int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  long long
  n;
  cin >> n;
  vector<string> v;
  for(long long i = 0; i<(1<<n); i++){
    v.push_back(bitset<16>(toGray(i)).to_string().substr(16-n, n));
  }
  for(auto i: v) cout << i << '\n';
  return 0;
}