#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int board[2*n+1][2*n+1], path[2*n+1][2*n+1];
		vector<int> par;
		memset(board, 1, sizeof board);
		for(int i = 0; i<2*n+1; i++) board[0][i] = board[i][0] = 1e9;
		for(int i = 1; i<2*n+1; i++){
			for(int j = 1; j<2*n+1; j++){
				cin >> board[i][j];
				board[i][j]++;
			}
		}
		priority_queue<pair<int, pair<int, int>>> pq;
		pq.push({0, {1, 1}});
		while(not pq.empty()){
			pair<int, pair<int, int>> u = pq.top();
			pq.pop();
			if(path[u.second.first][u.second.first]<-u.first) continue;
			
		}
	}
	return 0;
}