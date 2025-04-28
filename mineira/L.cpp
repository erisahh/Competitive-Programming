#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
	string s; cin >> s;
	int n; cin >> n;

	if (n == 1) {
		cout << s << endl; return;
	}

	int m = n;
	vector<string> vs;

	vector<char> ans(s.size(), '0');

	int idx = 0, pos = 0;
	int x = n * 2 - 3, y = 1;
	string nv = "";

	while (pos < s.size()) {
		ans[pos] = s[idx];
		idx++;
		pos += x + 1;
	}

	// for (auto u : ans) cout << u; cout << endl;

	n--;
	int j = 1;
	while (n > 1) {
		nv = "";
		pos = j;
		x = n * 2 - 3;

		bool ok = true;

		while (pos < s.size()) {
			ans[pos] = s[idx];
			idx++;
			if (ok) pos += x + 1;
			else pos += y + 1;
			
			ok = (ok ? false : true);
		}

		// for (auto u : ans) cout << u; cout << endl;

		n--;
		j++;
		y += 2;
	}

	pos = j;
	x = m * 2 - 3;
	while (pos < s.size()) {
		ans[pos] = s[idx];
		idx++;
		pos += x + 1;
	}
	for (auto u : ans) cout << u; cout << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
    solve();	
}

