#include <bits/stdc++.h>
using namespace std;


bool count_chars(int u){
	set<int> s;
	while(u) {
		s.insert(u%10);
		u/=10;
	}
	return s.size()<4;
}

int main(){
	int a;
	cin >> a;
	a++;
	while(count_chars(a)) a++;
	cout << a << '\n';
	return 0;
}