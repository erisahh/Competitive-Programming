#include <bits/stdc++.h>
#define int long long

using namespace std;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
int uniform(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

void solve(){
	int n = uniform(2, 100); // tamanho do array entre 2 e 100
	int x = uniform(2, 200); // valor alvo entre 2 e 200
	cout << n << " " << x << '\n';

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = uniform(1, 100); // valores entre 1 e 100
		cout << a[i] << ' ';
	}
	cout << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
    solve();	
}

