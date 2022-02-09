#include <bits/stdc++.h>
using namespace std;

const int N = 5e3+5;


int ans, sum, t;
bool b[N];
set<int> s;


int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &sum);
		ans = 1;
		sum--;
		s.clear();
		s.insert(1);
		s.insert(2);
		s.insert(3);
		while(sum){
			int aux = *s.lower_bound(sum);
			sum -= aux;
			s.insert(aux+1);
			s.insert(aux+2);
			ans++;
		}
		printf("%d\n", ans);
	}	
	return 0;
}
