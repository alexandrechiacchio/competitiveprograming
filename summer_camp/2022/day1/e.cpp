#include <bits/stdc++.h>
using namespace std;

int main(){
	int ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;
	if((ax+ay)%2!=(bx+by)%2){
		cout << "white\n";
	} else cout << "black\n";
	return 0;
}