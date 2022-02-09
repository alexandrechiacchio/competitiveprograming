#include <bits/stdc++.h>
using namespace std;

int t, k;
string s;
vector<string> v = {"22", "33" ,"55", "77", "25", "27", "35", "57", "32", "52", "72", "75"};

bool search_f(string u){
	bool flag = false;
	int pos = 0;
	while(pos < s.size()){
		if(not flag and (s[pos]==u[0])) flag = true;
		else if(flag and (s[pos]==u[1])) return true;
		pos++;
	}
	return false;
}

int main(){
	scanf("%d", &t);
	while(t--){
		cin >> k >> s;
		bool f = true;
		for(char i: s){
			if(i == '1' or i =='4' or i == '6' or i=='8' or i =='9'){
				cout << "1\n" << i << "\n";
				f = false;
				break;
			}
		}
		if(f){
			string aux;
			for(string i: v){
				if(search_f(i)){
					aux = i;
					break;
				}
			}
			cout << "2\n" << aux << "\n";
		}
	}
	return 0;
}