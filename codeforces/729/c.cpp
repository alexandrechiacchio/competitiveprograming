#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

long long ans, n, t;


int main(){
	scanf("%lld", &t);
	while(t--){
		ans = 0;
		scanf("%lld", &n);
		int aux = n/12, aux1 = n%12;
		aux = aux%MOD;
		ans = (33*aux)%MOD;
		if(aux1!=0){
			if(aux1==1) ans+=2;
			else if(aux1==2) ans+=5;
			else if(aux1==3) ans+=7;
			else if(aux1==4) ans+=10;
			else if(aux1==5) ans+=12;
			else if(aux1==6) ans+=16;
			else if(aux1==7) ans+=18;
			else if(aux1==8) ans+=21;
			else if(aux1==9) ans+=23;
			else if(aux1==10) ans+=26;
			else ans+=28;
			
		}
		ans +=(n/54)%MOD;
		ans = ans%MOD;
		printf("     %lld\n", (ans%MOD)%MOD);
	}
	return 0;
}

