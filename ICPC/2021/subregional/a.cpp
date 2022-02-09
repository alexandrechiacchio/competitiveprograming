//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
//define push_back eh coisa de fraco
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

const int N = 1e5+5;
const int MOD = 1e9+7;
const long double EPS = 1e-9;
const int PI = acos(-1.);
const int INF = 0x3f3f3f3f;


int main(){
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	pair<int, int> v[n+10];
	vector<set<int>> arr(k+10);
	for(int i = 0; i<n; i++){
		cin >> v[i].first >> v[i].second;
		arr[v[i].second].insert(v[i].first);
	}
	for(int i = 0; i<n; i++){
		v[i].first = *arr[v[i].second].begin();
		arr[v[i].second].erase(arr[v[i].second].begin());
	}
	bool ans = true;
	for(int i = 0; i<n-1; i++){
		if(v[i].first>v[i+1].first) ans = false;
	}
	if(ans) cout << "Y\n";
	else cout << "N\n";
	return 0;
}
