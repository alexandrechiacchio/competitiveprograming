#include <bits/stdc++.h>
using namespace std;

int k, n, s[2000], m[2000], sum;

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 0; i<n; i++){
		scanf("%d", &s[i]);
	}
	sort(s, s+n);
	for(int i = 0; i<k; i++) sum+=s[n-1-i];
	printf("%d", sum);
	return 0;
}
