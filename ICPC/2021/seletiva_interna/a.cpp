#include <bits/stdc++.h>
using namespace std;

int n, a[1010], sum;

int main(){
	scanf("%d", &n);
	for(int i = 0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i<n; i+=2){
		sum += a[i+1]-a[i];
	}
	printf("%d\n", sum);
	return 0;
}