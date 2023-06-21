#include <bits/stdc++.h>
using namespace std;
 
string s = "????????????????????????????????????????????????";
vector<int> v;
string path;
bool vis[9][9];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char toInt[] = {'D', 'U', 'R', 'L'};
 
 
int bt(int x, int y, int index) {
	if(vis[x][y]) return 0;
	if(x==7 and y==1){
		if(index == 48)	return 1;
		return 0;
	}
	if((vis[x+1][y] and vis[x-1][y] and !vis[x][y+1] and !vis[x][y-1]) or (!vis[x+1][y] and !vis[x-1][y] and vis[x][y+1] and vis[x][y-1])){
		return 0;
	}
	vis[x][y] = true;
	int ret = 0;
	if(v[index] == 4){
		for(int i = 0; i<4; i++) if(!vis[x+dx[i]][y+dy[i]]) {
			path.push_back(toInt[i]);
			ret += bt(x+dx[i], y+dy[i], index+1);
			path.pop_back();
		}
	} else {
		ret += bt(x+dx[v[index]], y+dy[v[index]], index+1);
	}
	vis[x][y] = false;
	return ret;
}
 
int main() {
	// time_t start = clock();
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	for(int i = 0; i<9; i++){
		vis[0][i] = true;
		vis[i][0] = true;
		vis[8][i] = true;
		vis[i][8] = true;
	}
	cin >> s;
	v.resize(s.size());
	for(int i = 0; i<(int)s.size(); i++){
		if(s[i] == 'D') v[i] = 0;
		else if(s[i] == 'U') v[i] = 1;
		else if(s[i] == 'R') v[i] = 2;
		else if(s[i] == 'L') v[i] = 3;
		else v[i] = 4;
	}
	cout << bt(1, 1, 0) << '\n';
	// time_t finish = clock();
	// cout << "Total time = " << finish - start << "ms\n";
	return 0;
}