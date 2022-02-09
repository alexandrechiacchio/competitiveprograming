#include <bits/stdc++.h>
using namespace std;

const int N = 1e9;

int t, n, a, b;
queue<long long> q;
bool aux;


int main(){
	scanf("%d", &t);
	while(t--){
		
		scanf("%d%d%d", &n, &a, &b);
		
		if((n-1%b)==0 or n%a==0){
			printf("Yes\n");
			continue;
		}
		
		while(n>1){
			if(n%a == 0) n/=a;
			else n-=b;
		}
		if(n==1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

