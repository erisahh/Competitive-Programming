#include <bits/stdc++.h>
#define int long long
#define T pair<int,int>

using namespace std;

void solve(){
	int k; string s; cin >> k >> s;

	char last = s[0];
	int ans = 0;

	if (k == 2) {
		int cont1 = 0, cont2 = 1;
		string a1 = s, a2 = s;
		a2[0] = (s[0] == '0' ? '1' : '0');

		for (int i = 1; i < s.size(); i++) {
			if (a1[i] == a1[i-1]) {
				a1[i] = (a1[i-1] == '0' ? '1' : '0'); cont1++;
			}
			if (a2[i] == a2[i-1]) {
				a2[i] = (a2[i-1] == '0' ? '1' : '0'); cont2++;
			}
		}

		if (cont1 < cont2) cout << cont1 << ' ' << a1 << endl;
		else cout << cont2 << ' ' << a2 << endl;

		return;
	}

	vector<T> v;
	T aux = {0, 0};
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == last) aux.second++;
		else {
			v.emplace_back(aux);
			aux.first = i; aux.second = i;
		}
		last = s[i];
	}
	v.emplace_back(aux);

	for (auto [l, r] : v) {
		if (r - l + 1 >= k) {
			char troca = (s[l] == '0' ? '1' : '0');

			for (int i = l + k - 1; i <= r; i += k) {
				if (i == r) {
					s[r - 1] = troca; ans++;
				}
				else {
					s[i] = troca; ans++;
				}
			}
		}
	}

	cout << ans << ' ' << s << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
    solve();	
}
