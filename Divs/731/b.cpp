#include <bits/stdc++.h>
using namespace std;

int top, bot, maxx, t;
char s[30];


bool check(){
	int aux = 0;
	for(int k = 'a'; k<'a'+(int)strlen(s); k++){
		for(int i = 0; i<(int)strlen(s); i++){
			if(s[i] == k) aux++;
		}
		if(aux!=1)	return false;
		aux = 0;
	}
	return true;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		bot = 0, top = strlen(s)-1;
		maxx = 'a'+(int)strlen(s);
		
		while(bot<top){
			if(s[bot]>=maxx or s[top]>=maxx){
				break;
			}
			if(s[bot]>s[top]){
				maxx = s[bot];
				bot++;
			}
			else {
				maxx = s[top];
				top--;
			}
		}
		if(bot==top and check()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
