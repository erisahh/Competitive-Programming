#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mx = 105;

int dp[mx][mx*mx];
int aux[mx][mx];

void solve(){
	int n; cin >> n;
	vector<int> a(n + 1);
	int s = 0;
	a[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s += a[i];
	}

	if (s & 1) cout << -1 << endl;
	else {
		dp[0][0] = 1;
		sort(a.begin(), a.end());

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= (s/2); j++) {

				dp[i][j] = dp[i-1][j];

				if (j - a[i] < 0) continue;
				dp[i][j] += dp[i-1][j-a[i]];
			}
		}

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= s/2; j++) cout << dp[i][j] << ' ';
			cout << endl;
		}
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
    solve();	
}

