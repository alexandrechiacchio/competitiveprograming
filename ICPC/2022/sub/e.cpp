#include <bits/stdc++.h>
using namespace std;

vector<int> v(1e5+10), h(1e6+10), a(1e6+10);


int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n, ans;
  cin >> n;
  for(int i = 0; i<n; i++){
    cin >> v[i];
    if(h[v[i]+1] == 0){
      ans++;
    
    }
  }
  return 0;
}