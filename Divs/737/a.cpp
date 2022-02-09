#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5+5;
 
int t, n, a[N];
long double sum1, sum2, ans;
 
 
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        sum1 = sum2 = 0;
        ans = -1e15;
        for(int i = 0; i<n; i++){
            scanf("%d", &a[i]);
            sum1+= a[i];
        }
        sort(a, a+n);
        for(int i = 0; i<n-1; i++){
            sum1 -= a[i];
            sum2 += a[i];
            ans = max(ans, sum1/(n-i-1)+sum2/(i+1));
        }
        printf("%.9Lf\n", ans);
    }
    return 0;
}