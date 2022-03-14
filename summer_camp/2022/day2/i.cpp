//ideia is right, UVA online jugde is shit

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long p = 31;
const long long m = 1e9 + 9;

vector<long long> h(N);
vector<long long> r_h(N);
vector <long long> p_pot(N);

int rabin_karp(string s) {
	string r_s = s;
	reverse(r_s.begin(), r_s.end());
	int S = s.size();


	for (int i = 0; i < S; i++) h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pot[i]) % m;
	for (int i = 0; i < S; i++) r_h[i + 1] = (r_h[i] + (r_s[i] - 'a' + 1) * p_pot[i]) % m;


	for (int i = 1; i < S; i++) {
		long long cur_h = (((h[i] - h[0] + m) % m) * p_pot[S - i]) % m;
		long long cur_r_h = (r_h[S] - r_h[S - i] + m) % m;

		long long curr_h = (h[S] - h[i] + m) % m;
		long long curr_r_h = (((r_h[S - i] - r_h[0] + m) % m) * p_pot[i]) % m;

		if ((cur_h == cur_r_h) and (curr_h == curr_r_h)) return 1;
	}

	if (h[S] == r_h[S]) return 2;
	else return 0;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	p_pot[0] = 1;
	for (int i = 1; i < (int)p_pot.size(); i++) p_pot[i] = (p_pot[i - 1] * p) % m;
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int aux = rabin_karp(s);
		if (aux == 0) cout << "simple\n";
		else if (aux == 1) cout << "alindrome\n";
		else cout << "palindrome\n";
	}

	return 0;
}