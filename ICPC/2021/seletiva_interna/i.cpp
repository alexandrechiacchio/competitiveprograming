#include <bits/stdc++.h>
using namespace std;

const int N = (1<<21);

int v[N], n, aux;
bool b[25];
vector<int>path;

int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

void print_s(int k){
	printf("printing state:\n %d ", k);
	for(int i = n-1; i>=0; i--){
		if((1<<i)&k) printf("1");
		else printf("0");
	}
	printf("\n");
}

void game(int state){
	path.push_back(state);
	while(state!=0){
		//print_s(state);
		if(v[state]!=0) break;
		int sum = 0;
		for(int i = 0; i<n; i++) if(state&(1<<i))sum++;
		state ^= (1<<(n-sum));
		path.push_back(state);
	}
	reverse(path.begin(), path.end());
		for(int j = 1; j<(int)path.size(); j++){
			//printf("v[%d] = %d\n", path[j], v[path[j-1]]+1);
			v[path[j]] = v[path[j-1]]+1;
		}
	path.clear();
}


int main(){
	scanf("%d", &n);
	for(int i = 1; i<(1<<n); i++){
		//printf("new game:\n");
		game(i);
	}
	//for(int i = 0; i<(1<<n); i++) printf("%d\n", v[i]);
	int num = 0;
	for(int i = 0; i<(1<<n); i++) num+=v[i];
	int den = (1<<n);
	int mdc = gcd(num, den);
	//printf("%d %d %d\n", num, den, mdc);
	num /= mdc;
	den /= mdc;
	printf("%d/%d\n", num, den);
	return 0;
}