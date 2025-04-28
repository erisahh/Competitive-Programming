#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
	int n, x; cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	int idx = -1;
	for (int i = 0; i < n ; i++) {
		if (a[i] >= x) continue;
		int aux = x - a[i];
		for (int j = 0; j < n; j++) {
			if (a[j] == aux and j != i)	idx = j;
		}
		if (idx != -1) {
			cout << i + 1 << ' ' << idx + 1 << endl; return;
		}
	}

	cout << "IMPOSSIBLE" << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
    solve();	
}

