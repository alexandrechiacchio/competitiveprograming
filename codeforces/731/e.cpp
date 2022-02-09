#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+5;


int q, n, k, a[N], t[N], temp[N];

void setTemp(int p){
	
	for(int i = a[p]; i<=n; i++){
		if(temp[i]>t[p]+abs(a[p]-i)) temp[i] = t[p]+abs(a[p]-i);
		else break;
	}
	for(int i = a[p]-1; i>0; i--){
		if(temp[i]>t[p]+abs(a[p]-i)) temp[i] = t[p]+abs(a[p]-i);
		else break;
	}
}

int main(){
	scanf("%d", &q);
	while(q--){
		scanf("%d%d", &n, &k);
		for(int i = 1; i<=k; i++) scanf("%d", &a[i]);
		for(int i = 1; i<=k; i++) scanf("%d", &t[i]);
		fill(temp, temp+N, INT_MAX);
		for(int i = 1; i<=k; i++) setTemp(i);
		for(int i = 1; i<n; i++) printf("%d ", temp[i]);
		printf("%d\n", temp[n]);
	}
	return 0;
}
