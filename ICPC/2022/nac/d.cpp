#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n, h, w;
  cin >> n >> h >> w;
  for(int i = 0; i<n; i++){
    char aux;
    cin >> aux;
    if(w == 0 or aux == 'Y'){
      cout << "Y ";
      w++;
      h--;
    } else cout << "N ";
    cin >> aux;
    if(h == 0 or aux == 'Y'){
      cout << "Y\n";
      w--;
      h++;
    } else cout << "N\n";
  }

  return 0;
}