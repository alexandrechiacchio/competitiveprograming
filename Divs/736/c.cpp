#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;


set<int> s[N];
int n, m, q, counter;
bool alive[N];

int main(){
    scanf("%d%d", &n, &m);
    memset(alive, true, N);
    for(int i = 0; i<m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        s[a].insert(b);
        s[b].insert(a);
        if(a>b) alive[b] = false;
        if(b>a) alive[a] = false;
    }
    for(int i = 1; i<=n; i++) if(alive[i]) counter++;
    scanf("%d", &q);
    while(q--){
        int a, b, c;
        scanf("%d", &c);
        if(c!=3){
            scanf("%d%d", &a, &b);
            if(c==1){
                s[a].insert(b);
                s[b].insert(a);
                if(alive[a] and a<*s[a].rbegin()){
                    alive[a] = false;
                    counter--;
                }
                if(not alive[a] and a>*s[a].rbegin()){
                    alive[a] = true;
                    counter++;
                }
                if(alive[b] and b<*s[b].rbegin()){
                    alive[b] = false;
                    counter--;
                }
                if(not alive[b] and b>*s[b].rbegin()){
                    alive[b] = true;
                    counter++;
                }
            }
            else {
                s[a].erase(b);
                s[b].erase(a);
                if(not s[a].empty()){
                    if(alive[a] and a<*s[a].rbegin()){
                        alive[a] = false;
                        counter--;
                    }
                    if(not alive[a] and a>*s[a].rbegin()){
                        alive[a] = true;
                        counter++;
                    }
                } else {
                    if(not alive[a]){
                        counter++;
                        alive[a] = true;
                    }
                }
                if(not s[b].empty()){
                    if(alive[b] and b<*s[b].rbegin()){
                        alive[b] = false;
                        counter--;
                    }
                    if(not alive[b] and b>*s[b].rbegin()){
                        alive[b] = true;
                        counter++;
                    }
                } else {
                    if(not alive[b]){
                        counter++;
                        alive[b] = true;
                    }
                }
            }
        }
        else {
            printf("%d\n", counter);
        }
    }
    return 0;
}