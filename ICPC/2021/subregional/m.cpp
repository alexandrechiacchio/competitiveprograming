//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//THESE ARE LAST DITCH EFFORTS!!!

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

vector<int> adj[N];
vector<int> line = {1};
vector<bool> vis(N), alive(N);

void dfs(int x) {
    vis[x] = true;
    for(auto e : adj[x]) {
        if(!vis[e]) {
            line.push_back(e);
            dfs(e);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    int ind = 2, ptr = 0;
    alive[1] = true;
    vector<pair<int, int>> v;
    while(q--) {
        int t, x;
        cin >> t >> x;
        if(t == 1) {
            adj[x].push_back(ind);
            v.push_back({t, ind});
            ind++;
        } else {
            v.push_back({t, x});
        }
    }
    dfs(1);
    for(auto k : v) {
        if(k.first == 1) {
            alive[k.second] = true;
        } else {
            alive[k.second] = false;
            while(alive[line[ptr]] == false and ptr<line.size()+1) ptr++;
						cout << line[ptr] << '\n';
        }
    }
    return 0;
}