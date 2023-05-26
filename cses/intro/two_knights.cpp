#include <bits/stdc++.h>
using namespace std;

int dx[] = {2, 2, 1, -1, -2, -2, -1, 1};
int dy[] = {-1, 1, 2, 2, -1, 1, -2, -2};


int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int k;
  cin >> k;
  for(long long i = 1; i<=k; i++){
    cout << (i*i)*(i*i-1)/2 - (i >= 3 ? (i-1)*(i-2)*4 : 0) << '\n';
  }
  return 0;
}