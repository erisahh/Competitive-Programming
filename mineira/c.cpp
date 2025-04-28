#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mx = 1e5+5;

int dp[mx];

void solve(){
	int n; cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	dp[1] = a[1];
	for (int i = 1; i <= n; i++) {
		if (i - 2 >= 0) dp[i] = max(dp[i - 2] + a[i], dp[i]);
		dp[i] = max(dp[i], dp[i - 1]);
	}
	
	// for (int i = 0; i <= n; i++) cout << dp[i] << ' '; cout << endl;

	cout << dp[n] << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
    solve();	
}

