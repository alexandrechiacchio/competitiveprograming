#include <bits/stdc++.h>
using namespace std;



int t, a[110], b[110], n, m, k;
vector<int> ans;
bool aux;


int main(){
	scanf("%d", &t);
	while(t--){
		ans.clear();
		scanf("%d%d%d", &k, &n, &m);
		for(int i = 0; i<n; i++){
			scanf("%d", &a[i]);
		}
		for(int i = 0; i<m; i++){
			scanf("%d", &b[i]);
		}
		int i, j;
		i = j = 0;
		aux = false;
		while(i<n or j<m){
			if(a[i]>k and b[j]>k){
				printf("-1\n");
				aux = true;
				break;
			}
			if(i<n and a[i]<=k){
				if(a[i] == 0) k++;
				ans.push_back(a[i]);
				i++;
			}
			if(j<m and b[j]<=k){
				if(b[j] == 0) k++;
				ans.push_back(b[j]);
				j++;
			}
		}
		if(aux) continue;
		for(int i: ans) printf("%d ", i);
		printf("\n");
	}
	return 0;
}
