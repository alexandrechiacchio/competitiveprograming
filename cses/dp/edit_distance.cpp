#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string a, b;
  cin >> a >> b;
  int n = a.size();
  int m = b.size();
  int dp[n + 10][m + 10];
  memset(dp, 0, sizeof dp);
  for(int i = 0; i<=n; i++) dp[i][0] = i;
  for(int i = 0; i<=m; i++) dp[0][i] = i;
  for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
    if(a[i-1] == b[j-1]) dp[i][j] = min({dp[i-1][j-1], dp[i-1][j] + 1, dp[i][j-1] + 1});
    else dp[i][j] = min({dp[i-1][j-1] + 1, dp[i-1][j] + 1, dp[i][j-1] + 1});
  }
  cout << dp[n][m] << "\n";
  return 0;
}

