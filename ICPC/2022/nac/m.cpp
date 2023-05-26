#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int r, c;
bool ans = false;

int vis[1010][110];

bitset<N> rotate_right(bitset<N> u){
  if(u[0] == true) u.set(c);
  u >>= 1;
  return u;
}

bitset<N> rotate_left(bitset<N> u){
  u <<= 1;
  if(u[c] == true){
    u.set(0);
    u.reset(c);
  }
  return u;
}

void debug(vector<bitset<N>> &maze, bitset<N> s, int pos){
  for(int i = 0; i<maze.size(); i++){
    cout << maze[i];
    if(i == pos) cout << ' ' << s;
    cout << '\n';
  }
  cout << '\n';
}

void bt(vector<bitset<N>> &maze, bitset<N> s, int pos, int col){
  // debug(maze, s, pos);
  if(ans) return;
  if(pos == r){
    ans = true;
    return;
  }
  for(int i = 0; i<c; i++){
    vis[pos][col] = true;
    if((rotate_left(s)&maze[pos]).any()) break;
    col = (col-1+c)%c;
    s = rotate_left(s);
  }
  for(int i = 0; i<c; i++){
    vis[pos][col] = true;
    if((maze[pos+1]&s).none() and !vis[pos+1][col]) bt(maze, s, pos+1, col);
    if(pos > 0 and (maze[pos-1]&s).none() and !vis[pos-1][col]) bt(maze, s, pos-1, col);
    if((rotate_right(s)&maze[pos]).any()) break;
    col = (col+1+c)%c;
    // cout << (maze[pos+1]&s) << ' ' << (maze[pos+1]&s).none() << '\n';
    s = rotate_right(s);
  }
}

int main(){
  // cin.tie(NULL);
  // ios_base::sync_with_stdio(false);
  string aux;
  cin >> r >> c >> aux;
  bitset<N> s(aux);
  vector<bitset<N>> maze;
  maze.push_back(bitset<N>(0));
  for (int i = 1; i<=r; i++){
    cin >> aux;
    maze.push_back(bitset<N>(aux));
  }
  bt(maze, s, 0, 0);
  // cout << "s = " << s << '\n';
  for(int i = 0; i < c/2; i++){
    bool hi = s.test(i), lo = s.test(c-1-i);
    if(hi) s.set(c-1-i);
    else s.reset(c-1-i);
    if(lo) s.set(i);
    else s.reset(i);
  }
  // cout << "s = " << s << '\n';
  memset(vis, 0, sizeof vis);
  bt(maze, s, 0, 0);

  if(ans) cout << "Y\n";
  else cout << "N\n";
  return 0;
}