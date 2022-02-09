#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

long long t, n, aux, ans, sum;

int main(){
	scanf("%lld", &t);
	while(t--){
		scanf("%lld", &n);
		ans = sum = 0;
		for(int i = 0; i<n; i++){
			scanf("%lld", &aux);
			sum += aux;
			sum = sum%n;
		}
		ans += (n-sum)*sum;
		printf("%lld\n", ans);
	}
	return 0;
}
