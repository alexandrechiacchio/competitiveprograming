#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> v;

string search(char c){
    for(int i = 0; i < (int)v.size(); i++){
        for(int j = 0; j < (int)v[i].size(); j++){
            if(v[i][j][0] == c){
                string s = v[i][j];
                v[i].clear();
                s[0] = toupper(s[0]);
                return s;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    for(int zz = 1; zz<=N; zz++){
        cout << "Case #" << zz << ":\n";
        int n;
        cin >> n;
        v.clear();
        v.resize(n);
        for(int i = 0; i<n; i++){
            int k;
            cin >> k;
            v[i].resize(k);
            for(int j = 0; j<k; j++){
                cin >> v[i][j];
                for(int z = 0; z<v[i][j].size(); z++) v[i][j][z] = tolower(v[i][j][z]);
            }
        }
				sort(v.begin(), v.end());
				for(int i = 0; i<n; i++){
					for(int j = 0; j<v[i].size(); j++){
						cout << v[i][j] << " ";
					}
					cout << '\n';
				}
        vector<string> ans(n);
        for(int i = n-1; i>=0; i--){
            ans.push_back(search('a'+i));
        }
        reverse(ans.begin(), ans.end());
        for(int i = 0; i<n; i++) cout << ans[i] << '\n';
    }
    return 0;
}