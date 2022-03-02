#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

string v[N];
bool w[N];

struct Node {
	int cnt = 0;
	Node *ch[27];
	Node () : cnt(0) {
		memset(ch, 0, sizeof ch);
	}
};

Node* root;
multiset<int> l[N];

void add (string s) {
	Node* cur = root;
	int depth = 0;
	for (auto c : s) {
		depth++;
		if (!cur->ch[c-'a']){
			cur->ch[c-'a'] = new Node();
			l[depth].insert(0);
		}
		cur = cur->ch[c-'a'];
		auto aux = l[depth].find(cur->cnt);
		int auxx = *aux;
		l[depth].erase(aux);
		l[depth].insert(auxx+1);
		cur->cnt++;
	}
}

void remove(string s){
	Node* cur = root;
	int depth = 0;
	for (auto c : s) {
		depth++;
		cur = cur->ch[c-'a'];
		auto aux = l[depth].find(cur->cnt);
		int auxx = *aux;
		l[depth].erase(aux);
		l[depth].insert(auxx-1);
		cur->cnt--;
	}
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	root = new Node();
	int q;
	cin >> q;
	memset(w, false, sizeof w);
	for(int zz = 1; zz<=q; zz++){
		int a;
		cin >> a;
		if(a==1){
			cin >> v[zz];
			w[zz] = true;
			reverse(v[zz].begin(), v[zz].end());
			add(v[zz]);
		} else if(a==2){
			int a, b;
			cin >> a >> b;
			if(not l[b].empty()){
				auto aux = l[b].rbegin();
				if(*aux>=a) cout << "YES\n";
				else cout << "NO\n";
			} else cout << "NO\n";
		} else {
			int b;
			cin >> b;
			if(w[b]) remove(v[b]);
			w[b] = false;
		}
	}
	return 0;
}