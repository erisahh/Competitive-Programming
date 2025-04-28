#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
	int q; cin >> q;

	int ans_a = 0, ans_inv = 0, sum = 0, n = 0;
	deque<int> a, inv;
	vector<int> ans;
	bool ok = true;

	for (int i = 0; i < q; i++) {
		int s; cin >> s;
		if (s == 1) {
			if (ok) {
				ans_a += sum - (n * a.back());
				a.emplace_front(a.back());
				a.pop_back();
				ans.emplace_back(ans_a);

				ans_inv += -sum + (n * inv.front());
				inv.emplace_back(inv.front());
				inv.pop_front();
			}
			else {
				ans_inv += sum - (n * inv.back());
				inv.emplace_front(inv.back());
				inv.pop_back();
				ans.emplace_back(ans_inv);

				ans_a += -sum + (n * a.front());
				a.emplace_back(a.front());
				a.pop_front();
			}
		}
		if (s == 2) {
			ok = (ok ? false : true);
			if (ok) ans.emplace_back(ans_a);
			else ans.emplace_back(ans_inv);
		}
		if (s == 3) {
			int k; cin >> k;
			sum += k;
			n++;
			if (ok)	{
				a.emplace_back(k);
				inv.emplace_front(k);

				ans_a += n * k; 
				ans_inv += sum;
			}
			else {
				a.emplace_front(k);
				inv.emplace_back(k);

				ans_a += sum; 
				ans_inv += n * k;
			}
			
			if (ok) ans.emplace_back(ans_a);
			else ans.emplace_back(ans_inv);
		}
		// cout << "ans_a = " << ans_a << " ans_inv = " << ans_inv << endl;
		// cout << "sum = " << sum << endl;
		// cout << "n = " << n << endl;

		// for (auto u : a) cout << u << ' '; cout << endl;
		// for (auto u : inv) cout << u << ' '; cout << endl;
		// cout << endl;
	}

	for (auto u : ans) cout << u << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--)
    solve();	
}

