#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
	return b? gcd(b, a%b) : a;
}

long long t, a, b, ans, moves;

int main(){
	scanf("%lld", &t);
	while(t--){
		scanf("%lld%lld", &a, &b);
		if(a<b) swap(a,b);
		ans = a-b;
		if(ans == 0){
			printf("0 0\n");
			continue;
		}
		if(gcd(a,b)!=ans) moves = min(b, min(b%ans, ans-b%ans));
		else moves = 0;
		printf("%lld %lld\n", ans, moves);
	}
	return 0;
}
