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
		int score[3] = {0, 0, 0};
		vector<string> v[3];
		v[0].resize(n);
		v[1].resize(n);
		v[2].resize(n);
		for(int i = 0; i<n; i++) cin >> v[0][i]; 
		for(int i = 0; i<n; i++) cin >> v[1][i]; 
		for(int i = 0; i<n; i++) cin >> v[2][i]; 
		sort(v[0].begin(), v[0].end());
		sort(v[1].begin(), v[1].end());
		sort(v[2].begin(), v[2].end());
		for(int i = 0; i<n; i++){
			int cnt = 0;
			if(binary_search(v[1].begin(), v[1].end(), v[0][i])) cnt++;
			if(binary_search(v[2].begin(), v[2].end(), v[0][i])) cnt++;
			if(cnt == 0) score[0] += 3;
			if(cnt == 1) score[0] += 1;
		}
		for(int i = 0; i<n; i++){
			int cnt = 0;
			if(binary_search(v[0].begin(), v[0].end(), v[1][i])) cnt++;
			if(binary_search(v[2].begin(), v[2].end(), v[1][i])) cnt++;
			if(cnt == 0) score[1] += 3;
			if(cnt == 1) score[1] += 1;
		}
		for(int i = 0; i<n; i++){
			int cnt = 0;
			if(binary_search(v[1].begin(), v[1].end(), v[2][i])) cnt++;
			if(binary_search(v[0].begin(), v[0].end(), v[2][i])) cnt++;
			if(cnt == 0) score[2] += 3;
			if(cnt == 1) score[2] += 1;
		}
		for(int i: score) cout << i << " ";
		cout << '\n';
	}

	return 0;
}