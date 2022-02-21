#include <bits/stdc++.h>
using namespace std;

struct Node {
	int cnt = 0;
	Node *ch[27], *par;
	Node () : cnt(0) {
		memset(ch, 0, sizeof ch);
	}
};

Node* root;

void add (string s) {
	Node* cur = root;
	cur->cnt++;
	for (auto c : s) {
		if (!cur->ch[c-'a']){
			cur->ch[c-'a'] = new Node();
			cur->ch[c-'a']->par = cur;
		}
		cur = cur->ch[c-'a'];
		cur->cnt++;
	}
	if (!cur->ch[26]) cur->ch[26] = new Node();
	cur = cur->ch[26];
	cur->cnt++;
}

void remove(string s){
	Node* cur = root;
	cur->cnt++;
	for (auto c : s) {
		if (!cur->ch[c-'a']) cur->ch[c-'a'] = new Node();
		cur = cur->ch[c-'a'];
		cur->cnt--;
	}
}

bool ans;

void count (int l, int k, int cnt, Node *u = root) {
	if(u->cnt == 0 or ans){
		return;
	}
	if(l == cnt){
		ans = true;
		return;
	}
	for(int i = 0; i<27; i){
		if(u->ch[i]!=0) {
			count(l, k, cnt+1, u->ch[i]);
			if(ans) return;
		}
	}
	return;
}



int main(){
	freopen("in.txt", "r", stdin);
	root = new Node();
	int q;
	cin >> q;
	vector<string> v;
	vector<bool> w;
	map<int, int> m;
	for(int zz = 1; zz<=q; zz++){
		int a;
		cin >> a;
		if(a==1){
			string s;
			cin >> s;
			v.push_back(s);
			w.push_back(true);
			m[zz] = v.size()-1;
			add(s);
		} else if(a==2){
			ans = false;
			int l, k;
			cin >> k >> l;
			count(l, k, 0);
			if(ans) cout << "Yes\n";
			else cout << "No\n";
		} else {
			int b;
			cin >> b;
			if(w[m[b]]) remove(v[m[b]]);
			w[m[b]] = false;
		}
	}
	return 0;
}