#include <bits/stdc++.h>
using namespace std;

int t, p, a, b;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &p);
        a = p-1;
        b=2;
        while(p%b!=1 and b<p) b++;
        printf("%d %d\n", b, a);
    }
    return 0;
}