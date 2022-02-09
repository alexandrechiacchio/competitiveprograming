#include <bits/stdc++.h>
using namespace std;


int main(){
	int l, r, t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &l, &r);
	printf("%d\n", r%max(r/2+1, l));
	}
	return 0;
}