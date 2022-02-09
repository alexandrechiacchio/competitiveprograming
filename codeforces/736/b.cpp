#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;


int t, n, ans;
char e[N], f[N], v[N];

int main(){
    scanf("%d", &t);
    while(t--){
        ans = 0;
        scanf("%d", &n);
        memset(v, 0, n);
        scanf("%s", e);
        scanf("%s", f);
        
        for(int i = 0; i<n; i++){
            if(f[i]=='1'){
                if ((not (v[i]=='1')) and (not (e[i]=='1'))){
                    v[i] = '1';
                    ans++;
                }
                else if((not (v[i-1]=='1')) and (e[i-1]=='1') and (i>0)){
                    v[i-1] = '1';
                    ans++;
                }
                else if((not (v[i+1]=='1')) and (e[i+1]=='1') and (i<n-1)){
                    v[i+1] = '1';
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}



// 111
// 111