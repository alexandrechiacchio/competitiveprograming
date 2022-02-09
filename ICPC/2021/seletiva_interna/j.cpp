#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e3+5; 
const int L = 310; 
int ans, n, H, h[N], s[N], S;
long long w[N], dp[L][L+L];
 
int main(){
    scanf("%d%d%d", &n, &H, &S);
    for (int i = 0; i < n; i++) scanf("%d%d%lld", &h[i], &s[i], &w[i]);
    for (int i = 0; i < n; i++){ 
        for (int j = H; j >= h[i]; j--){
			for(int k = H+S; k >= s[i]+h[i]; k--){
            	dp[j][k] = max(dp[j][k], w[i]+ dp[j-h[i]][k-s[i]-h[i]]);
			}
		}
	}
    ans = dp[H-1][S+H-1];
	printf("%lld\n", ans);
	return 0;
}