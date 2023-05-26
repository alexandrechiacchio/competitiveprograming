#include <bits/stdc++.h>
using namespace std;


int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--){
    int a, b;
    cin >> a >> b;
    if(a<b) swap(a, b);
    if((a > 2*b) or ((b-(a-b))%3)) cout << "NO\n";
    else cout << "YES\n";
  }
  return 0;
}