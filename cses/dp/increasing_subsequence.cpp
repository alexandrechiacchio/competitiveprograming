#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> x(n);
	for(int i = 0; i<n; i++) cin >> x[i];
	vector<int> aux;
	for(int i = 0; i<n; i++){
		auto it = lower_bound(aux.begin(), aux.end(), x[i]);
		if(it == aux.end()) aux.push_back(x[i]);
		else {
			*it = x[i];
		}
	}
	cout << aux.size() << '\n';
	return 0;
}