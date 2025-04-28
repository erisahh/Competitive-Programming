#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9+7;
const int mx = 1e6+6;

int fat[mx];

int fexp(int a, int b) {
	if (b == 0) return 1;
	if (!(b & 1)) return fexp(a * a % MOD, b / 2);
	return a * fexp(a, b - 1) % MOD;
}

int inv(int n) {
	return fexp(n, MOD - 2);
}

int escolhe(int n, int i) { // n escolhe i
	return fat[n] * inv(fat[n - i]) % MOD * inv(fat[i]) % MOD;
}

void solve(){
	fat[0] = 1;
	for (int i = 1; i < mx; i++) fat[i] = i * fat[i - 1] % MOD;

	int a, b, n; cin >> a >> b >> n;

	int ans = 0;
	for (int i = 0; i <= n; i++) {
		int sum = a * i + (n - i) * b;
		bool exc = true;
		while (sum > 0) {
			if (sum % 10 != a and sum % 10 != b) exc = false;
			sum /= 10;
		}
		if (!exc) continue;
		ans = (ans + escolhe(n, i)) % MOD;
	}

	cout << ans << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
    solve();	
}

