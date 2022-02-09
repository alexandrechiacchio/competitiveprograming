#include <bits/stdc++.h>
using namespace std;

int n, a[110], b[110], ans;

int main(){
	scanf("%d", &n);
	for(int i = 0; i<n; i++){
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(a, a+n);
	for(int i = 0; i<n; i++) if(a[i]==b[i])ans++;
	printf("%d\n", ans);
	return 0;
}