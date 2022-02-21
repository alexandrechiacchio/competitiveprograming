//MLE
#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> ans;
int n, m;
vector<vector<int>> board;
queue<pair<int, int>> q;

bool check(int x, int y){
	int c;
	if(board[x][y]!=-1) c = board[x][y];
	else if(board[x+1][y]!=-1) c = board[x+1][y];
	else if(board[x][y+1]!=-1) c = board[x][y+1];
	else if(board[x+1][y+1]!=-1) c = board[x+1][y+1];
	else return false;
	return ((c == board[x][y] or board[x][y] == -1) and
					(c == board[x+1][y] or board[x+1][y] == -1) and 
					(c == board[x][y+1] or board[x][y+1] == -1) and
					(c == board[x+1][y+1] or board[x+1][y+1] == -1));
}

int count(int x, int y){
	int out = 0;
	if(board[x][y]!=-1) out++;
	if(board[x+1][y]!=-1) out++;
	if(board[x][y+1]!=-1) out++;
	if(board[x+1][y+1]!=-1) out++;
	return out;
}

void debug(){
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cout << setw(2) << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << '\n';
}

void mark(int x, int y){
	int c;
	if(board[x][y]!=-1) c = board[x][y];
	board[x][y] = -1;
	if(board[x+1][y]!=-1) c = board[x+1][y];
	board[x+1][y] = -1;
	if(board[x][y+1]!=-1) c = board[x][y+1];
	board[x][y+1] = -1;
	if(board[x+1][y+1]!=-1) c = board[x+1][y+1];
	board[x+1][y+1] = -1;
	ans.push_back({{x, y}, c});
	//debug();
}

void add_to_queue(int x, int y){
	if(x>0 and y>0 and check(x-1, y-1)) q.push({x-1, y-1});
	if(x>0 and check(x-1, y)) q.push({x-1, y});
	if(x>0 and y<m-2 and check(x-1, y+1)) q.push({x-1, y+1});
	if(y<m-2 and check(x, y+1)) q.push({x, y+1});
	if(x<n-2 and y<m-2 and check(x+1, y+1)) q.push({x+1, y+1});
	if(x<n-2 and check(x+1, y)) q.push({x+1, y});
	if(x<n-2 and y>0 and check(x+1, y-1)) q.push({x+1, y-1});
	if(y>0 and check(x, y-1)) q.push({x, y-1});
}

void find(){
	for(int i = 0; i<n-1; i++){
		for(int j = 0; j<m-1; j++){
			if(check(i, j)){
				q.push({i ,j});
			}
		}
	}
}

int main(){
	// cin.tie(NULL);
	// ios_base::sync_with_stdio(false);
	cin >> n >> m;
	board.resize(n, vector<int>(m));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin >> board[i][j];
		}
	}
	find();
	int cnt = n*m;
	while(not q.empty() and cnt){
		pair<int, int> u = q.front();
		q.pop();
		if(check(u.first, u.second)){
			cnt-= count(u.first, u.second);
			mark(u.first, u.second);
		}
		add_to_queue(u.first, u.second);
	}
	bool f = true;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(board[i][j]!=-1) f=false;
		}
	}
	if(f){
		reverse(ans.begin(), ans.end());
		cout << ans.size() << '\n';
		for(int i = 0; i<ans.size(); i++){
			cout << ans[i].first.first+1 << " " << ans[i].first.second+1 << " " << ans[i].second << "\n";
		}
	} else cout << "-1\n";
	return 0;
}