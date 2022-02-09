#include <bits/stdc++.h>
using namespace std;



int a, b, n, t, ans;
char s[110];




int main(){
	scanf("%d", &t);
	while(t--){
		ans = 0;
		scanf("%d%d%d", &n, &a, &b);
		scanf("%s", s);
		if(b>0){
			ans = n*(a+b);
		}
		else {
			int i, j;
			i = 0, j = 1;
			while(i<n){
				j = i+1;
				while(s[j]==s[0] and j<n) j++;
				i = j;
				if(i==n) break;
				while(s[j]==s[i] and j<n) j++;
				for(int k = 0; k<n-i+1; k++){
					s[k+i] = s[k+j];
				}
				//printf("%s\n", s);
				n-=j-i;
				ans += (j-i)*a+b;
			}
			ans+= n*a+b;
		}
		printf("%d\n", ans);
	}
	return 0;
}
