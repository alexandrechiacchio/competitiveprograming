#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int t, n, a[N];
list<int> l;

int main(){
	cin >> t; 
	while(t--){
		cin >> n;
		for(int i = 0; i<n; i++) cin >> a[i];
		l.push_back(a[0]);
		for(int i = 1; i<n; i++){
			if(a[i]>*l.begin()) l.push_back(a[i]);
			else l.push_front(a[i]);
		}
		for(int i: l) cout << i << " ";
		cout << "\n";
		l.clear();
	}
	return 0;
}