#include <bits/stdc++.h>
using namespace std;

const int N = 1e2, MOD = 1e9+7;

vector<int> p;
vector<vector<int>> pf;

void sieve(){
	bool pr[N];
	memset(pr, 0, sizeof pr);
	for(int i = 2; i<N; i++){
		if(pr[i]) continue;
		p.push_back(i);
		for(int j = i*i; j<N; j+=i) pr[j] = true;
	}
}

vector<int> factor(int u){
	vector<int> out(25);
	for(int i = 0; i<p.size() and u!=1; i++){
		while(u%p[i]==0){
			out[i]++;
			u/=p[i];
		}
	}
	return out;
}

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
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	sieve();
	int n;
	cin >> n;
	pf.resize(n+1, vector<int>(25));
	for(int i = 1; i<=n; i++){
		int a;
		cin >> a;
		pf[i] = factor(a);
		for(int j = 0; j<25; j++) pf[i][j] += pf[i-1][j];
		
	}
	int t;
	cin >> t;
	while(t--){
		int l, r, m;
		cin >> l >> r >> m;
		vector<int> aux(25);
		long long ans = 1;
		for(int i = 0; i<25; i++){
			aux[i] = pf[r][i]-pf[l-1][i];
			ans = (ans*fexp(p[i], aux[i], m))%m;
		}
		cout << ans << '\n';
	}
	return 0;
}