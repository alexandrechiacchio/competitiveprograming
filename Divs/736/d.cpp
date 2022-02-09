#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5+5;


int t, n, ans;
ll dp[N][20], a[N];

ll gcd(ll a, ll b){
    if(a==0) return b;
    if(b==0) return a;
    if(a%b) return gcd(b, a%b);
    return b;
}

bool check(int a, int b){

}

int main(){
    scanf("%d", &t);
    while(t--){
        ans = 1;
        scanf("%d", &n);
        memset(dp, 0, sizeof(ll)*N*20);
        for(int i = 0; i<n; i++)scanf("%lld", &a[i]);
        for(int i = 0; i<n-1; i++) a[i] = abs(a[i+1]-a[i]);
        for(int i = 0; i<n; i++) dp[i][0] = a[i];
        for(int k = 1; (1<<k)<=n; k++){
            for(int i = 0; i<n; i++){
                if( (i+(1<<(k-1))) < n )dp[i][k] = gcd(dp[i][k-1], dp[i+(1<<(k-1))][k-1]);
            }
        }

        for(int k = 0; (1<<k)<=n; k++){
            for(int i = 0; i<n; i++){
                printf("%2d ", dp[i][k]);
            }
            printf("\n");
        }




        for(int i = 0; i<n-1; i++){
            int lo = i, hi = n-1;
            int mid = (lo+hi/2);

            while(lo<hi){
                printf("%d %d %d\n", lo, mid, hi);
                int aux = 20;
                while(((1<<aux) > mid-i)) aux--;
                if(gcd(dp[i][aux], dp[mid-(1<<aux)][aux]) == 1) hi = mid-1;
                else lo = mid;
                mid = (lo+hi)/2;
            }
            printf("%d %d\n", i, mid);
               
            ans = max(ans, mid-i+1);
        }
        printf("%d\n", ans);
    }
    return 0;
}
