#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int cntw, cntb;
	cntw = cntb = 0;
	vector<char> v(n);
	for(int i = 0; i<n; i++){
		cin >> v[i];
		if(v[i] == 'W') cntw++;
		else cntb++;
	}
	vector<int> ans;
	if(cntw%2==0){
		for(int i = 0; i<n-1; i++){
			if(v[i] == 'W'){
				ans.push_back(i);
				v[i] = 'B';
				if(v[i+1] == 'W') v[i+1] = 'B';
				else v[i+1] = 'W';
			}
		}
	} else if(cntb%2==0){
		for(int i = 0; i<n-1; i++){
			if(v[i] == 'B'){
				ans.push_back(i);
				v[i] = 'W';
				if(v[i+1] == 'B') v[i+1] = 'W';
				else v[i+1] = 'B';
			}
		}
	} else {
		bool f = true;
		for(int i = 1; i<n; i++) if(v[i]!=v[0]) f = false;
		if(f) cout << "0\n";
		else cout << "-1\n";
		return 0;
	}
	cout << ans.size() << '\n';
	for(int i: ans) cout << i+1 << " ";
	cout << '\n';
	return 0;
}