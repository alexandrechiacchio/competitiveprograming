#include <bits/stdc++.h>
using namespace std;

int p[] = {0,7,27,41,49,63,78,108}, n, t, aux, sum;

int main(){
	scanf("%d", &t);
	while(t--){
		sum = 0;
		scanf("%d", &n);
		for(int i = 0; i<n; i++){
			int aux;
			scanf("%d", &aux);
			sum+=p[aux];
		}
		if(sum>=120)sum-=50;
		else if(sum>=89) sum-=30;
		else if(sum>=69) sum-=15;
		printf("%d\n", sum);
	}
	return 0;
}