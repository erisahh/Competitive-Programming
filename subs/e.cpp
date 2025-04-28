#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
	int n; cin >> n;
	int m[n][n];

	pair<int,int> p;
	int mini = 1e5+5;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
			if (m[i][j] <= mini) {
				mini = m[i][j];
				p.first = i; p.second = j;
			}
		}
	}
	
	if (p.first == 0 && p.second == 0) { cout << 0 << endl; return;}
	if (p.first == 0 && p.second == n-1) { cout << 1 << endl; return;}
	if (p.first == n-1 && p.second == n-1) { cout << 2 << endl; return;}
	if (p.first == n-1 && p.second == 0) { cout << 3 << endl; return;}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
    solve();	
}

