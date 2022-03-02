#include <bits/stdc++.h>
using namespace std;


int v[60], t, n;

void print(){
	for(int i = 0; i<n; i++) cout << v[i] << " ";
	cout << '\n';
}

void check(){
	for(int i = 0; i<n-2; i++){
		if(v[i]+v[i+1]!=v[i+2]) continue;
		while(v[i]+v[i+1]==v[i+2]){
			next_permutation(v+i, v+i+3);
		}
		i=max(0, i-3);
	}
}

int main(){
	// cin.tie(NULL);
	// ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i<n; i++){
			v[i] = i+1;
		}
		int aux = n;
		while(aux--){
			check();
			print();
			next_permutation(v, v+n);
		}
	}
	return 0;
}