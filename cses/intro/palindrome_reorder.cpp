#include <bits/stdc++.h>
using namespace std;


int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int cntSort['z' - 'a' + 1];
  memset(cntSort, 0, sizeof cntSort);
  string s;
  cin >> s;
  for(char c: s) cntSort[c-'A']++;
  int oddCnt = 0;
  for(int i = 0; i < 'z' - 'a' + 1; i++){
    if(cntSort[i]%2==1){
      oddCnt++;
      if(oddCnt > 1){
        cout << "NO SOLUTION\n";
        return 0;
      }
    }
  }
  for(int i = 0; i< 'z' - 'a' + 1; i++) if(cntSort[i]%2==0){
    for(int j = 0; j<cntSort[i]/2; j++){
      cout << (char)('A' + i);
    }
  }
  for(int i = 0; i< 'z' - 'a' + 1; i++) if(cntSort[i]%2==1){
    for(int j = 0; j<cntSort[i]; j++) cout << (char)('A' + i);
  }
  for(int i = 'z'-'a'; i >= 0; i--) if (cntSort[i]%2==0) {
    for(int j = 0; j<cntSort[i]/2; j++){
      cout << (char)('A' + i);
    }
  }
  return 0;
}