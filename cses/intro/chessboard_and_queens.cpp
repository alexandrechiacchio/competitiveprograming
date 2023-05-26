#include <bits/stdc++.h>
using namespace std;

vector<string> reserved(8);
int ans;

bool check(int *board, int x, int y){
  for(int i = 0; i<y; i++){
    if(board[y-i-1] == x) return false;
    if(abs(board[y-i-1] - x) == i+1) return false;
  }
  return true;
}

void bt(int *board, int c){
  if(c == 8){
    ans++;
    return;
  }
  for (int i = 0; i<8; i++) if(check(board, i, c) and reserved[i][c] == '.'){
      board[c] = i;
      bt(board, c+1);
  }
}

int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  for(int i = 0; i<8; i++) cin >> reserved[i];
  int board[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  bt(board, 0);
  cout << ans << '\n';
  return 0;
}