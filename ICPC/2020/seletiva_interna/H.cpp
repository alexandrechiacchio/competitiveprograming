#include <bits/stdc++.h>
using namespace std;
#define MOD = 1e19;

long long unsigned int c;
multiset<long long unsigned int> s;
vector<long long unsigned int> v;

int main(){
	v.push_back(2);
	for(int i = 3; 100000; i+=2){
		for(long long unsigned int j = 1; j<v.size(); j++){
			if(i%v[j]==0){
				goto end;
			}
		}
		v.push_back(i);
		end:;
	}
	scanf("%d", &c);
	while(c!=1){
		
	}
	return 0;
}
