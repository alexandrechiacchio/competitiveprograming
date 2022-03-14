//not solved
#include <bits/stdc++.h>
using namespace std;

const long long N = 1e12+12;

long long t, n;
vector<long long> v;

void make_fact(){
	long long aux = 6;
	for(int i = 4; aux<N; i++){
		v.push_back(aux);
		aux*=i;
	}
}

int count_bits(long long u){
	int cnt = 0;
	for(int i = 0; i<=40; i++){
		if((1ll<<i) & u) cnt++;
	}
	return cnt;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	make_fact();
	cin >> t;
	while(t--){
		cin >> n;
		int k = count_bits(n);
		for(int i = 1; i<(1<<12); i++){
			long long sum = 0;
			for(int j = 0; j<12; j++) if((1<<j) & i){
				sum+=v[j];
			}
			k = min(k, count_bits(i)+count_bits(n-sum));
		}
		cout << k << '\n';
	}
	return 0;
}