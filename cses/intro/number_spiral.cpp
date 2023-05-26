#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while(t--){
    long long x, y;
    cin >> x >> y;
    long long num = max(x, y);
    num = (num)*(num-1)/2;
    num = 2*num+1;
    if(x<y){
      if(y&1) num += y-x;
      else num -= y-x; 
    } else {
      if(x&1) num -= x-y;
      else num += x-y;
    }
    cout << num << '\n';
  }
  return 0;
}