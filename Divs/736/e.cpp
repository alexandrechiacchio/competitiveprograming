#include <bits/stdc++.h>
using namespace std;

const long long N = 2e5+5, MOD = 1e9+7;


long long n, q, x, ans;

long long fexp(long long b, long long e){
    long long ans = 1;
    while(e){
        if(e&1) ans = (ans*b) % MOD;
        b = (b*b) % MOD;
        e /= 2;
    }
    return ans;
}

long long fact(long long u){
    long long ans = 1;
    for(long long i = 1; i<=u; i++) ans = (ans*i)%MOD;
    return ans;
}

long long inv(long long u){
    return fexp(u, MOD-2);
}

long long comb(long long u, long long v){
	if(u==0 or u<v) return 0;
    return (((fact(u)*inv(fact(u-v)))%MOD)*inv(fact(v)))%MOD;
}

int main(){
    scanf("%lld%lld", &n, &q);
    while(q--){
        scanf("%lld", &x);
        long long aux = x/3;
        ans = 0;
        if(x%3==0) aux--;
        for(long long i = aux; i<=n; i++){
            ans = (ans+comb(3*i, x))%MOD;
        }
        printf("%lld\n", (ans+MOD)%MOD);
    }
    return 0;
}
