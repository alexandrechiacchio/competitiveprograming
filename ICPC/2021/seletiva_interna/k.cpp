#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int t, n, k, m, a[N], h[N], turn[N];
set<int> pot;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &k, &m);
		for(int i=0; i<n; i++)scanf("%d", &a[i]);
		for(int i = 0; i<2*n; i++){
			if(pot.find(a[i%n]) == pot.end()) pot.insert(a[i%n]);
			else{
				turn[i%n]++;
				pot.erase(a[i%n]);
			}
		}
		for(int i = 0; i<n; i++) h[i] += (m/n/2)*turn[i];
		for(int i = 0; i<m%(2*n); i++){
			if(pot.find(a[i%n]) == pot.end()) pot.insert(a[i%n]);
			else{
				h[i%n]++;
				pot.erase(a[i%n]);
			}
		}
		for(int i = 0; i<n-1; i++) printf("%d ", h[i]);
		printf("%d\n", h[n-1]);
		memset(h, 0, 4*n);
		memset(turn, 0, 4*n);
		pot.clear();
	}
	return 0;
}