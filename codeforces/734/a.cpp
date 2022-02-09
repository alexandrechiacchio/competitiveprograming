#include <bits/stdc++.h>
using namespace std;

int t, n, c1, c2;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        c1 = c2 = n/3;
        if(n%3==1) c1++;
        else if(n%3==2) c2++;
        printf("%d %d\n", c1, c2);
    }
    return 0;
}