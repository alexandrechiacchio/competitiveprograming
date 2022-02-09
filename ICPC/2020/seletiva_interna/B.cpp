#include <bits/stdc++.h>
using namespace std;

char name[110][20];
int n, at[110], df[110], hp[110], ans[3], aux;
bool wins[110][110];
set<pair<int, pair<int, int>>> a;

int fight(int a, int b){
	if((at[a]-df[b])<=0 && (at[b]-df[a]<=0)) return -1;
	if((at[a]-df[b])<=0 && (at[b]-df[a]>0)) return b;
	if((at[a]-df[b])>0 && (at[b]-df[a]<=0)) return a;
	int rndsA = hp[b]/max(0, at[a]-df[b]), rndsB = hp[a]/max(0, at[b]-df[a]);
	if((hp[b]%(at[a]-df[b]))!=0) rndsA++;
	if((hp[a]%(at[b]-df[a]))!=0) rndsB++;
	//printf("%d %d", rndsA, rndsB);
	if(rndsA>rndsB){
		//printf("%s ganha de %s em %d rounds\n", name[b], name[a], rndsB);
		return b;
	}
	else if(rndsA<rndsB){
		//printf("%s ganha de %s em %d rounds\n", name[a], name[b], rndsA);
		return a;
	}
	else{
		//printf("%s empata com %s em %d rounds\n", name[a], name[b], rndsA);
		return -1;
	}
}

void printw(){
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			printf("%d ", wins[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int main(){
	scanf("%d", &n);
	for(int i = 0; i<n; i++) scanf("%s %d %d %d", name[i], &hp[i], &at[i], &df[i]); 
	for(int i = 0; i<n; i++) for(int j = i+1; j<n; j++){
		aux = fight(i, j);
		if(aux==i) wins[i][j]=true;
		else if(aux==j) wins[j][i]=true;
	}
	//printw();
	for(int i = 0; i<n; i++) for(int j = 0; j<n; j++){
		if(wins[i][j]==1){
			for(int k = 0; k<n; k++) {
				if(wins[j][k]==1 and wins[k][i]==1){
					ans[0] = i;
					ans[1] = j;
					ans[2] = k;
					sort(ans, ans+3);
					a.insert(make_pair(ans[0], make_pair(ans[1], ans[2])));
				}
			}
		}
	}
	printf("%d\n", (int)a.size());
	pair<int, pair<int, int>>h;
	for(auto it = a.begin(); it!=a.end(); it++){
		pair<int, pair<int, int>>h = *it;
		printf("%s %s %s\n", name[h.first], name[h.second.first], name[h.second.second]);
	}
	printf("%ld\n", clock());
	return 0;
}
