#include <bits/stdc++.h>
using namespace std; 

const int N = 2e5+5;

int t, n, a[N];

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i<n; i++) cin >> a[i];
		sort(a, a+n);
		bool f = false;
		long long sum1 = a[0]+a[1], sum2 = a[n-1], pos1 = 1, pos2 = n-1;
		while(pos1<pos2 and not f){
			if(sum1<sum2) f = true;
			pos1++;
			pos2--;
			sum1+=a[pos1];
			sum2+=a[pos2];
		}
		if(f) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}