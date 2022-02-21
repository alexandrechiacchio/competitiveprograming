#include <bits/stdc++.h>
using namespace std;



int main(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i<n; i++){
		cin >> a[i] >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int l, r, cnt, ans;
	l = r = cnt = ans = 0;
	while(l<n and r<n){
		if(a[l]<b[r]){
			cnt++;
			l++;
		} else if(a[l]>b[r]){
			cnt--;
			r++;
		} else {
			r++;
			l++;
		}
		ans = max(ans, cnt);
	}
	cout << ans << '\n';
	return 0;
}