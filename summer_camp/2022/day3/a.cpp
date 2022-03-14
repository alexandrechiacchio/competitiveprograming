#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, a, b, c, cur_a, cur_b, cur_c, ans = 1;
	cur_a = cur_b = cur_c = 1;
	cin >> n >> a >> b >> c;
	int board[n+1];
	memset(board, 0, sizeof board);
	for(int i = 0 ; i<1e7; i++){
		cur_a = (cur_a+a)%(n+1);
		if(board[cur_a] == 0 or board[cur_a] == 1 or cur_a == 1) board[cur_a] = 1, ans++;
		else {
			cout << ans;
			return 0;
		}
		cur_b = (cur_b+b)%(n+1);
		if(board[cur_b] == 0 or board[cur_b] == 2  or cur_b == 1) board[cur_b] = 2, ans++;
		else {
			cout << ans;
			return 0;
		}
		cur_c = (cur_c+c)%(n+1);
		if(board[cur_c] == 0 or board[cur_c] == 3  or cur_c == 1) board[cur_c] = 3, ans++;
		else {
			cout << ans << '\n';
			return 0;
		}
	}
	cout << "3000000000" << '\n';
	return 0;
}