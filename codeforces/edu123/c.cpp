#include <bits/stdc++.h>
using namespace std;


const int N = 5e3+10, INF = 0x3f3f3f3f;

int t, n, v[N], r, l;
bool b[N];

void kadane(){
	int cur_max, old_max;
	old_max = cur_max = -INF;
	int rr, ll;
	l = ll = 0;
	r = rr = 1;
	for(int i = 0; i<n; i++){
		if(cur_max+v[i]>cur_max){
			rr = i+1;
			cur_max+=v[i];
		} else if(v[i]<0){
			ll = i;
			cur_max = v[i];
		}
		if(old_max<cur_max){
			l = ll;
			r = rr;
			old_max = cur_max;
		}
	}
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i<n; i++) cin >> v[i];
		for(int i = 0; i<n; i++){
			kadane();
			int len = r-l;
			while()
		}

	}

	return 0;
}