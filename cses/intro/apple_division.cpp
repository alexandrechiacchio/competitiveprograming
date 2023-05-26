#include <bits/stdc++.h>
using namespace std;


int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  long long min_diff = LONG_LONG_MAX;
  for (long long i = 0; i < (1 << n); i++) {
    long long sum1 = 0, sum2 = 0;
    for (long long j = 0; j < n; j++) {
      if ((1 << j) & i) sum1 += v[j];
      else sum2 += v[j];
    }
    min_diff = min(min_diff, abs(sum1 - sum2));
  }
  cout << min_diff << '\n';
  return 0;
}