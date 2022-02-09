#include <bits/stdc++.h>
using namespace std;

int t, n, par, impar, aux;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i<2*n; i++){
			scanf("%d", &aux);
			if(aux%2) impar++;
			else par++;
		}
		if(impar!=par) printf("No\n");
		else printf("Yes\n");
		par = impar = 0;
	}
	return 0;
}
