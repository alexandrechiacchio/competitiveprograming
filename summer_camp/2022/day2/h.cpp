#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;

int t, h, w;
char brd[N][N];
int vis[N][N], fire[N][N];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
queue<pair<int, int>> q;
pair<int, int> start;


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> w >> h;
		memset(fire, 0, sizeof fire);
		memset(vis, 0, sizeof vis);
		for(int i = 0; i<h; i++){
			for(int j = 0; j<w; j++){
				cin >> brd[i][j];
				if(brd[i][j] == '*'){
					q.push({i, j});
					fire[i][j] = 1;
				}
				if(brd[i][j] == '@'){
					vis[i][j] = 1;
					start = {i, j};
				}
			}
		}
		while(not q.empty()){
			int x = q.front().first, y = q.front().second;
			q.pop();
			for(int i = 0; i<4; i++){
				if(!fire[x+dx[i]][y+dy[i]] and x+dx[i]>=0 and x+dx[i]<h and y+dy[i]>=0 and y+dy[i]<w and brd[x+dx[i]][y+dy[i]] != '#'){
					fire[x+dx[i]][y+dy[i]] = fire[x][y] + 1;
					q.push({x+dx[i], y+dy[i]});
				}
			}
		}
		q.push(start);
		while(not q.empty()){
			int x = q.front().first, y = q.front().second;
			q.pop();
			for(int i = 0; i<4; i++){
				if((x+dx[i]>=0) and (x+dx[i]<h) and (y+dy[i]>=0) and (y+dy[i]<w) and (!vis[x+dx[i]][y+dy[i]]) and (brd[x+dx[i]][y+dy[i]] != '#') and (fire[x+dx[i]][y+dy[i]]==0 or vis[x][y]+1<fire[x+dx[i]][y+dy[i]])){
					vis[x+dx[i]][y+dy[i]] = vis[x][y] + 1;
					q.push({x+dx[i], y+dy[i]});
				}
			}
		}
		bool f = false;
		int ans = 0x3f3f3f3f;
		for(int i = 0; i<h; i++){
			if(vis[i][0]){
				ans = min(ans, vis[i][0]);
				f = true;
			}
			if(vis[i][w-1]){
				ans = min(ans, vis[i][w-1]);
				f = true;
			}
		}
		for(int i = 0; i<w; i++){
			if(vis[0][i]){
				ans = min(ans, vis[0][i]);
				f = true;
			}
			if(vis[h-1][i]){
				ans = min(ans, vis[h-1][i]);
				f = true;
			}
		}
		if(f){
			cout << ans << '\n';
		} else {
			cout << "IMPOSSIBLE\n";
		}
	}
	return 0;
}