#include <bits/stdc++.h>
#define int long long
#define T pair<string,int>

using namespace std;

void solve(){
	int k, n; cin >> k >> n;

	// X
	// -
	// --
	
	string ans = "";
	queue<T> q;
	q.emplace("X-", 1);
	q.emplace("-X", 1);

	while (!q.empty()) {
		auto [p, val] = q.front();
		int ps = p.size();
		q.pop();
	
		if (val == k && p.size() == n) {
			ans = p; break;	
		}

		if (p.back() == 'X') {
			for (int i = 1; i <= 2; i++) {
				if (ps + i < n) {
					p += '-'; q.emplace(p, val);
				}
			}
		}
		else {
			if (ps + 1 <= n) {
				p += 'X'; q.emplace(p, val + 1);
			}
		}
	}

	if (ans == "") cout << '*' << endl;
	else cout << ans << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
    solve();	
}

