#include <bits/stdc++.h>
using namespace std;


string tolo(string s){
	for(int i = 1; i<s.size(); i++) s[i] = tolower(s[i]);
	s[0] = toupper(s[0]);
	return s;
}



int main(){
	int t;
	cin >> t;
	for(int zz = 1; zz<=t; zz++){
		cout << "Case #" << zz << ":\n";
		int n;
		cin >> n;
		vector<set<int>> w(26);
		vector<vector<string>> v(n);
		for(int i = 0; i<n; i++){
			int k;
			cin >> k;
			for(int j = 0; j<k; j++){
				string s;
				cin >> s;
				v[i].push_back(tolo(s));
				w[v[i][j][0]-'A'].insert(i);
			}
		}
		int cnt = 0;
		vector<string> ans(n);
		while(cnt<n){
			int pos;
			for(int i = 0; i<n; i++) if(w[i].size()==1){
				pos = i;
				break;
			}
			int aux = *w[pos].begin();
			for(int i = 0; i<v[aux].size(); i++){
				w[v[aux][i][0]-'A'].erase(w[v[aux][i][0]-'A'].find(aux));
				if(v[aux][i][0]=='A'+pos){
					ans[pos] = v[aux][i];
					cnt++;
				}
			}
			v[aux].clear();
		}
		for(int i = 0; i<n; i++) cout << ans[i] << '\n';
	}
}