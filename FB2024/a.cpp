#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
	string s; cin >> s;
	map<char,int> f;
	for (auto u : s) {
		if (f[u]) continue;
		f[u]++;
	}

	string x = "";
	for (auto [alfa, val] : f) x += alfa;

	int ans = s.size() - x.size();
	cout << ans << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
    solve();	
}

