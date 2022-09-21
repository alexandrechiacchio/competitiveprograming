#include <bits/stdc++.h>
using namespace std;

long long rect[1010][1010];

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int q, n;
		cin >> n >> q;
		memset(rect, 0, sizeof rect);
		for(int i = 0; i<n; i++){
			int a, b;
			cin >> a >> b;
			rect[a][b] += a*b;
		}
		for(int i = 1; i<1010; i++) for(int j = 1; j<1010; j++){
			rect[i][j] = rect[i][j] + rect[i-1][j] + rect[i][j-1] - rect[i-1][j-1];
		}
		while(q--){
			int hs, ws, hb, wb;
			cin >> ws >> hs >> wb >> hb;
			cout << rect[wb-1][hb-1] - rect[wb-1][hs] - rect[ws][hb-1] + rect[ws][hs] << '\n';
		}
	}
	return 0;
}