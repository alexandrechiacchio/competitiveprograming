#include <bits/stdc++.h>
using namespace std;


// dp[i][j][k] = até peça de tamanho i, faltando j e k nos lados repectivamente


int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n, k, e;
  cin >> n >> k >> e;
  
  cout << dp[n][0][0] << '\n';
  return 0;
}