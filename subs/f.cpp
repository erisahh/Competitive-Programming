#include <bits/stdc++.h>
#define int long long
#define ii pair<int,int>

using namespace std;

void solve(){
	int n; cin >> n;
	vector<ii> p;
	p.emplace_back(1 , 1);
	for (int i = 1; i <= n; i++) {
		auto [a, b] = p.back();
		p.emplace_back(b, a + b);	
	}

	cout << p[n].first << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
    solve();	
}

