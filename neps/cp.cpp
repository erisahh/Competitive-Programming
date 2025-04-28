#include <bits/stdc++.h>
#define int long long
#define T pair<int,int>

using namespace std;

const int mx = 1e3+3;

const int INF = 1e18;

vector<T> adj[mx];
int dist[mx];
int n, m;

void dijkstra(int s) {
	for (int i = 0; i < mx; i++) dist[i] = INF;

	dist[s] = 0;
	priority_queue<T, vector<T>, greater<>> pq;
	pq.emplace(dist[s], s);

	while (!pq.empty()) {
		auto [d, v] = pq.top();
		pq.pop();

		if (dist[v] != d) continue; 

		for (auto [w, u] : adj[v]) {
			if (dist[u] > d + w) {
				dist[u] = d + w;
				pq.emplace(dist[u], u);
			}
		}
	}
}

void solve(){
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, c; cin >> u >> v >> c;
		adj[u].emplace_back(c, v);
		adj[v].emplace_back(c, u);
	}

	dijkstra(0);

	// for (int i = 0; i <= n + 1; i++) cout << dist[i] << ' '; cout << endl;
	cout << dist[n + 1] << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
    solve();	
}

