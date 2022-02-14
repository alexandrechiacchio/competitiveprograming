#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10, INF = 0x3f3f3f3f;

vector<int> dp(N, INF);

int get_digit(int u, int k){
	while(k){
		u/=10;
		k--;
	}
	return u%10;
}

int count_digits(int u){
	int cnt = 0;
	while(u) {
		cnt++;
		u/=10;
	}
	return cnt;
}

int _dp(int u){
	for(int i = u; i>=0; i--){
		int digits = count_digits(i);
		for(int j = 0; j<digits; j++){
			int digit = get_digit(i, j);
			if(i-digit>=0) dp[i-digit] = min(dp[i-digit], dp[i]+1);
		}
	}

	return dp[0];
}

int main(){
	int n;
	cin >> n;
	dp[n] = 0;
	cout << _dp(n) << "\n";
	return 0;
}