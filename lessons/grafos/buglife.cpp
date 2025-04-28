#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mx = 2e3+3;

vector<int> adj[mx];
vector<int> cor(mx), vis(mx);

bool dfs(int v, int c) {
	vis[v] = 1;
	cor[v] = c;	
	for (auto u : adj[v]) {
		if (!vis[u]) {
			if (dfs(u, c xor 1)) return true;
		}
		else if (cor[u] == cor[v]) return true;
	}
	return false;
}

void solve(){
	int n, m; cin >> n >> m;	

	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}

	bool aux = false, ans = false;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) aux = dfs(i, 0);
		if (aux) ans = true;
	}
	if (ans) cout << "Suspicious bugs found!\n";
	else cout << "No suspicious bugs found!\n";

	for (int i = 0; i < n; i++) {
		vis[i] = 0;
		cor[i] = 0;
		adj[i].clear();
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	int i = 1;
	while (i <= t) {
		cout << "Scenario #" << i << ':' << endl;
		solve();
		i++;
	}
}

