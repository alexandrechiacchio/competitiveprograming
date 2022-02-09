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
		vector<int> p(n+1);
		for(int i = 1; i<=n; i++){
			if(p[i]!=0) continue;
			vector<int> v;
			int a;
			cout << "? " << i << '\n';
			cout.flush();
			cin >> a; 
			v.push_back(a);
			while (a!=v[0] or v.size()<=1){
				cout << "? " << i << '\n';
				cout.flush();
				cin >> a;
				v.push_back(a);
			}
			int n = v.size();
			for(int j = 1; j<n; j++) v.push_back(v[j]);
			a = 0;
			while(v[a]!=i) a++;
			for(int j = a; j<n+a; j++){
				p[v[j]] = v[j+1];
			}
		}
		cout << "! ";
		for(int i = 1; i<=n; i++) cout << p[i] << " ";
		cout << '\n';
		cout.flush();
	}
	return 0;
}