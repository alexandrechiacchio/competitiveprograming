#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.size();
		int cnt1 = 0, cnt2 = 0;
		for(int i = 0; i<n; i++){
			if(s[i]=='E')cnt1++;
			else cnt2++;
		}
		if((s[n-1]=='E' and (cnt2>=2 or cnt2==0)) or (s[n-1]=='N' and cnt2>1)) cout << "YES\n";
		else cout << "NO\n"; 
	}
	return 0;
}