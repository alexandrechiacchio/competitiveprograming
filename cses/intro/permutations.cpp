#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  if(n == 2 or n == 3) cout << "NO SOLUTION\n";
  else {
    for(int i = 1; i<=n/2; i++) cout << 2*i << ' ';
    for(int i = 0; i<=(n-1)/2; i++) cout << 2*i+1 << ' ';
  }
  return 0;
}