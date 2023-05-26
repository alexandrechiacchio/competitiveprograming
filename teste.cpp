#include <bits/stdc++.h>
using namespace std;


int main(){
	vector<int> v = {1, 2, 3, 4};
	auto it = v.begin();
	cout << *it << '\n';
	it++;
	cout << *it << " " << *++it << " " << *it++ << "\n";
	return 0;
}