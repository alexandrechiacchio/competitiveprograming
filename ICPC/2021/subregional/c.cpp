//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
//define push_back eh coisa de fraco
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

const int N = 1e5+5;
const int MOD = 1e9+7;
const long double EPS = 1e-9;
const int PI = acos(-1.);
const int INF = 0x3f3f3f3f;

long long fexp(long long b, long long e, long long m = MOD){
	long long ans = 1;
    while(e){
        if(e&1) ans = (ans*b) % m;
        b = (b*b) % m;
        e /= 2;
    }
    return ans;
}

int main(){
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long b, l;
	cin >> b >> l;
	long long d[l];
	for(int i = 0; i<l; i++){
		cin >> d[i];
	}
	long long aux = 0, m = b+1;
	for(int i = 0; i<l; i++){
		aux = (aux+(d[l-1-i]*fexp(b, i, m))%m)%m;
	}
	if(aux==0){
		cout << "0 0\n";
	} else {
		for(int i = 0; i<l; i++){
			long long a = fexp(b, l-1-i, m);
			if((aux%a==0) and (d[i]-aux/a>=0)){
				cout << i+1 << " " << d[i]-aux/a << '\n';
				return 0;
			}
		}
		cout << "-1 -1\n";
	}
	return 0;
}
