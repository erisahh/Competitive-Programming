#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
	int k, n; cin >> k >> n;

	if (n == 1) {
		if (n == k) cout << 'X' << endl;
		else cout << '*' << endl;
		return;
	}

	int x;
	if (n & 1) x = n/2 + 1;
	else x = n/2;

	if (x < k) {cout << '*' << endl; return;}

	int aux = n, cont = 1;
	string s = "-"; aux--;
	while (aux >= 3) {
		aux -= 3;
		s += "X--"; cont++; 
	}

	if (aux == 0) s.back() = 'X';
	else if (aux == 1) s += 'X';
	else if (aux == 2) s += "X-";
	//cout << s << endl;

	if (cont == k) { cout << s << endl; return;}

	bool ok = true;
	for (int i = 1; i < n - 1; i += 3) {
		if (!ok) ok = true;
		else {
			s[i - 1] = 'X'; s[i] = '-'; s[i + 1] = 'X';
			cont++; ok = false;
		}

		if (cont == k) {
			cout << s << endl; return;
		}
	}

	cout << '*' << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
    solve();	
}

