#include <bits/stdc++.h>
using namespace std;

stack<int> pin[3];

void cmp(stack<int>* u, stack<int>* v) {
  if (u->empty() or (!v->empty() and v->top() < u->top())) swap(u, v);
  v->push(u->top());
  u->pop();
  cout << u - pin + 1 << " " << v - pin + 1 << '\n';
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) pin[0].push(n - i);
  cout << (1 << n) - 1 << '\n';
  if (n & 1) {
    for (int i = 0; i < (1 << n) - 1; i++) {
      if (i % 3 == 0) cmp(pin, pin + 2);
      if (i % 3 == 1) cmp(pin, pin + 1);
      if (i % 3 == 2) cmp(pin + 1, pin + 2);
    }
  } else {
    for (int i = 0; i < (1 << n) - 1; i++) {
      if (i % 3 == 0) cmp(pin, pin + 1);
      if (i % 3 == 1) cmp(pin, pin + 2);
      if (i % 3 == 2) cmp(pin + 1, pin + 2);
    }
  }
  return 0;
}