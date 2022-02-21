#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    for(int zz = 1; zz<=t; zz++){
        int n, m;
        cin >> n >> m;
        int candy = 0;
        for(int i = 0; i<n; i++){
            int a;
            cin >> a;
            candy+=a;
        }
        cout << "Case #" << zz << ": " << candy%m << '\n';
    }
    return 0;
}