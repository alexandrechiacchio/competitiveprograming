#include <bits/stdc++.h>
using namespace std;

const long long N = 2e5+10;

long long t, n, x, ans;
multiset<long long> ms;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n >> x;
		for(long long i = 0; i<n; i++){
			long long a;
			cin >> a;
			ms.insert(a);
		}
		ans = 0;
		while(not ms.empty()){
			long long aux = *ms.begin();
			if(ms.find(x*aux)==ms.end()) ans++;
			else ms.erase(ms.find(x*aux));
			ms.erase(ms.begin());
		}
		cout << ans << '\n';
	}
	return 0;
}