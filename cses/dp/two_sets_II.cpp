#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

long long fexp(long long b, long long e, long long m = MOD){
	long long ans = 1;
    while(e){
        if(e&1) ans = (ans*b) % m;
        b = (b*b) % m;
        e /= 2;
    }
    return ans;
}

long long inv(long long u, long long m = MOD){
  return fexp(u, MOD-2);
}

int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int sum = (n + 1) * n / 2;
  if(sum&1){
    cout << "0\n";
    return 0;
  }
  vector<long long> dp(sum);
  dp[0] = 1;
  for(int j = 1; j<=n; j++){
    for(int i = sum/2; i>=0; i--){
      dp[i+j] = (dp[i+j]+dp[i])%MOD;
    }
  }
  cout << ((dp[sum/2]*inv(2))+MOD)%MOD << '\n';
  return 0;
}