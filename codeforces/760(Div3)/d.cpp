#include <bits/stdc++.h>
using namespace std;


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n, k, score = 0;
		cin >> n >> k;
		vector<int> v(n);
		for(int i = 0; i<n; i++) cin >> v[i];
		sort(v.begin(), v.end());
		multiset<int> aux;
		for(int i = n-2*k; i<n; i++) aux.insert(v[i]);
		auto a = aux.rbegin(), b = aux.rbegin();
		a++;
		while(not aux.empty()){
			if(*aux.begin()==*aux.rbegin()){
				score+=aux.size()/2;
				break;
			}
			if(*b/(*a)>=1) a++;
			else {
				aux.erase(aux.find(*a));
				aux.erase(aux.find(*b));
				a = aux.rbegin();
				a++;
				b = aux.rbegin();
			}
		}
		for(int i = 0; i<n-2*k; i++) score+=v[i];
		cout << score << '\n';
	}
}