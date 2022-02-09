#include <bits/stdc++.h>
using namespace std;

char c, w[1000];
int s;


int main(){
	scanf(" %c %d %s", &c, &s, w);
	if(c=='E'){
		for(int i = 0; w[i]!='\0'; i++){
			if(w[i]+s>'z') w[i]-=26-s;
			else w[i]+=s;
		}
	}
	else {
		for(int i = 0; w[i]!='\0'; i++){
			if(w[i]-s<'a') w[i]+=26-s;
			else w[i]-=s;
		}
	}
	printf("%s\n", w); 
	return 0;
}
//abcdefghijklmnopqrstuvwxyz
