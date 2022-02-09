#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int t, n, v[N], ans, a[N], b[N], arr[N];
list<int> l;


void merge(int bot, int top){
	if(bot==top) return;
	int m = (bot+top)/2, n1 = m-bot+1, n2 = top-m;
	merge(bot, m), merge(m+1, top);
	for(int i = 0; i<n1; i++) a[i] = arr[bot+i];
	for(int i = 0; i<n2; i++) b[i] = arr[m+1+i];
	int i = 0, j = 0, k = bot;
	while((i<n1) && (j<n2)){
		if(a[i]<=b[j]) arr[k] = a[i], i++;
		else arr[k] = b[j], j++, ans+=n1-i;
		k++;
	}
	while(i<n1) arr[k] = a[i], i++, k++;
	while(j<n2) arr[k] = b[j], j++, k++;	
}

bool check(int u, int size){
	int inv1, inv2;
	for(auto it = l.begin(); it!=l.end(); it++){
		if(*it>u) inv1++;
		if(*it<u) inv2++;
	}
	return inv1<inv2;
}

int main(){
	cin >> t; 
	while(t--){
		cin >> n;
		ans = 0;
		for(int i = 0; i<n; i++) cin >> v[i];
		l.push_back(v[0]);
		for(int i = 1; i<n; i++){
			if(check(v[i], i)) l.push_back(v[i]);
			else l.push_front(v[i]);
		}
		ans = 0;
		for(int i = 0; i<n; i++){
			arr[i] = *l.begin();
			cout << arr[i] << " ";
			l.pop_front();
		}
		cout << endl;
		merge(0, n-1);
		cout << ans << "\n";
		l.clear();
	}
	return 0;
}