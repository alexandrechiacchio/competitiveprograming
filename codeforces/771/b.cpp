#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> even, odd;
		for(int i = 0; i<n; i++){
			int a;
			cin >> a;
			if(a&1) odd.push_back(a);
			else even.push_back(a);
		}
		vector<int> aux = even;
		sort(aux.begin(), aux.end());
		if(aux != even){
			cout << "No\n";
			continue;
		}
		aux = odd;
		sort(aux.begin(), aux.end());
		if(aux != odd){
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
	}
	return 0;
}