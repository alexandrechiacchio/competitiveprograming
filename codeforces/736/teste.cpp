#include <bits/stdc++.h>
using namespace std;


int main(){
    int i = 10;
    while(i>-32){
        printf("2^%d = %d\n", i, 1<<i);
        i--;
    }
    return 0;
}