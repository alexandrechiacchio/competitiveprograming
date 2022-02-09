#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;


int n, m, q, v[N];
int main(){
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i<=n; i++){
		v[i] = i;
	}
	for(int i = 0; i<m; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		v[a] = max(v[a], b);
	}
	for(int i = 1; i<=n; i++){
		v[i] = max({v[i], v[i-1]});
		//printf("%3d ", v[i]);
	}
	//printf("\n");
	for(int i = 0; i<q; i++){
		int l, r;
		scanf("%d%d", &l, &r);
		if(l>r) swap(l, r);
		if(v[l]>=r) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
