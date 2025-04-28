#include <bits/stdc++.h>
#define int long long

using namespace std;

const int INF = 1e9+9;

int n, m, k, q; 
vector<vector<int>> pref;

bool check(int i, int j, int x, int y) {
	if (pref[x][y] - pref[i - 1][y] - pref[x][j - 1] + pref[i - 1][j - 1] == k * k)	return true;
	return false;
}

void solve(){
	cin >> n >> m >> k >> q;
	
	vector<vector<int>> mat(n + 1, vector<int> (m + 1, INF));
	vector<vector<int>> aux(n + 1, vector<int> (m + 1, 0));
	pref.assign(n + 1, vector<int> (m + 1, 0));

	while (q--) {
		int a, b, d; cin >> a >> b >> d;
		mat[a][b] = d;
	}

	int l = 0, r = INF, ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (mat[i][j] <= mid) aux[i][j] = 1;
			}
		}


		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + aux[i][j];
			}
		}

		bool ok = false;
		for (int i = 1; i <= n; i++) {
			if (i + k - 1 > n) continue;

			for (int j = 1; j <= m; j++) {
				if (j + k - 1 > m) continue;
				if (check(i, j, i + k - 1, j + k - 1)) ok = true;
			}
		}

		if (ok) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) pref[i][j] = 0, aux[i][j] = 0;
		}
	}

	cout << (ans == INF ? -1 : ans) << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
    solve();	
}

