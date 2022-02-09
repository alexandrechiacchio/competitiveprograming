#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int t, n, k, ans[N], max_size, v[N];
set<int> s[N];
priority_queue<pair<int, int>> pq;
stack<pair<int, int>> stck;

void printq(){
    priority_queue<pair<int, int>> bla = pq;
    while(not bla.empty()){
        printf("%d %d\n", -bla.top().first, bla.top().second);
        bla.pop();
    }
}




int main(){
    freopen("in.txt", "r", stdin);
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &k);
        while(not pq.empty()) pq.pop();
        while(k--) pq.push({0, k+1});
        for(int i = 0; i<n; i++){
            int aux;
            scanf("%d", &aux);
            v[i] = aux;
            pair<int, int> u = pq.top(), q;
            printq();
            if(s[u.second].find(aux)!=s[u.second].end()){
                printf("not paiting %d pos with color %d\n", i, u.second);
                while(pq.top().first==u.first){
                    stck.push(pq.top());
                    pq.pop();
                    q = pq.top();
                    if(s[q.second].find(aux)==s[q.second].end()) break;
                }
            }
            if(q.first!=u.first){
                while(not stck.empty()){
                    pq.push({stck.top().first, stck.top().second});
                    stck.pop();
                }
                continue;
            }
            pq.pop();
            s[u.second].insert(aux);
            printf("painting %d pos with color %d\n", i, u.second);
            ans[i] = u.second;
            pq.push({u.first-1, u.second});
            max_size = max(max_size, (int)s[u.second].size());
        }
        /*
        bool fix = false;
        for(int i = 0; i<k; i++) if((int)s[i].size()!=max_size){
            fix = true;
            break;
        }
        if(fix) for(int i = 0; i<k; i++){
            if((int)s[i].size() == max_size){
                ans[*s[i].begin()] = 0;
                s[i].erase(s[i].begin());
            }
        } */
        printf("ans: \n");
        for(int i = 0; i<n; i++) printf("%2d ", v[i]);
        printf("\n");
        for(int i = 0; i<n; i++) printf("%2d ", ans[i]);
        printf("\n");
    }
    return 0;
}