#include <bits/stdc++.h>
using namespace std;

int t, xa, ya, xb, yb, xf, yf, ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &xa, &ya);
		scanf("%d%d", &xb, &yb);
		scanf("%d%d", &xf, &yf);
		ans = abs(xa-xb) + abs(ya-yb);
		
		if((xa==xb and xa==xf) and ((ya>yf and yb<yf) or (ya<yf and yb>yf))) ans += 2;
		if((ya==yb and ya==yf) and ((xa>xf and xb<xf) or (xa<xf and xb>xf))) ans += 2;
		
		printf("%d\n", ans);
		ans = 0;
	}
	
	
	return 0;
}
