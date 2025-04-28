#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9+7;
const int mx = 1e6+6;

vector<int> spf(mx, -1), divs(mx, 0), pot(mx, 0), ans(mx, -1);

void calc_spf() {
	for (int i = 2; i < mx; i++) {
		if (spf[i] != -1) continue;
		spf[i] = i;
		for (int j = i+i; j < mx; j += i) {
			if(spf[j] != -1) continue;
			spf[j] = i;
		}
	}
}

vector<int> factorize(int x) {
	vector<int> aux;
	while (x > 1) {
		aux.emplace_back(spf[x]);
		x /= spf[x];
	}
	return aux;
}

void calc_pot() {
	pot[0] = 1;
	for (int i = 1; i < mx; i++) pot[i] = pot[i-1]*2 % MOD;
}

void solve(){
	calc_spf();
	calc_pot();
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		vector<int> aux = factorize(x), v;
		int last = -1;
		for (int j = 0; j < aux.size(); j++) {
			if (aux[j] != last) v.emplace_back(aux[j]);
			last = aux[j];
		}	

		for (int j = 0; j < (1 << v.size()); j++) {
			int y = j, idx = 0, m = 1;
			while (y > 0) {
				if (y & 1) { m *= v[idx];}
				idx++;
				y /= 2;
			}
			divs[m]++;
		}
	}

	//for (int i = 0; i < 10; i++) cout << i << ' ' << divs[i] << endl;

	int q; cin >> q;
	while (q--) {
		int x; cin >> x;

		if (ans[x] != -1) cout << ans[x] << endl;
		else {
			vector<int> aux = factorize(x), v;
			int last = 0;
			for (int j = 0; j < aux.size(); j++) {
				if (aux[j] != last) {
					v.emplace_back(aux[j]);
				}
				last = aux[j];
			}	

			int good = 0;
			for (int mask = 0; mask < (1 << v.size()); mask++) {
				int y = mask, idx = 0, cont = 0, m = 1;
				//	cout << "mask = " << mask << endl;
				while (y > 0) {
					if (y & 1) { 
						m *= v[idx];
						cont++;
					}
					idx++;
					y /= 2;
				}
				if (cont & 1) good -= divs[m];
				else good += divs[m];
				/*	cout << "cont = " << cont << endl;
					cout << "m = " << m << endl;
					cout << "divs[m] = " << divs[m] << endl;
					cout << "good = " << good << endl << endl;*/
			}

			cout << pot[good] << endl;
			ans[x] = pot[good];
		}
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
    solve();	
}

