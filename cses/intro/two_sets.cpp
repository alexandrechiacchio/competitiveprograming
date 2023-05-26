#include <bits/stdc++.h>
using namespace std;


int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  long long sum = (n + 1) * n / 2;
  if (sum & 1) {
    cout << "NO\n";
  }
  else {
    cout << "YES\n";
    set<long long> s;
    long long sSum = 0;
    for (int i = n; i > 0; i--) {
      if (sSum + i <= sum / 2) {
        sSum += i;
        s.insert(i);
      }
    }
    cout << s.size() << '\n';
    for (auto it = s.begin(); it != s.end(); it++) cout << *it << " ";
    cout << '\n' << n - s.size() << '\n';
    for (int i = 1; i <= n; i++) if (!s.count(i)) cout << i << " ";
    cout << '\n';
  }
  return 0;
}