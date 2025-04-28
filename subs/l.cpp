#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> a;
	map<int,int> f;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		a.emplace_back(x);
		int aux = 0;
		while (x > 0) {
			if(x & 1) f[(1 << aux)]++;
			aux++;
			x /= 2;
		}
	}

	sort(a.rbegin(), a.rend());
	for (int i = 0; i < n; i++) {
		int x = a[i], aux = 0;
		//cout << "i = " << i << endl;
		while (x > 0) {
			if (!(x & 1) && f[(1 << aux)] > 0) {
				a[i] |= (1 << aux);
				f[(1 << aux)]--;
			}
			else if ((x & 1) && !f[(1 << aux)] > 0) {
				//cout << "entra aq em = " << (1 << aux) << endl;  
				a[i] ^= (1 << aux);
			}
			else if ((x & 1) && f[(1 << aux)]) f[(1 << aux)]--;
			aux++;
			x /= 2;
		}	
	}

	for (auto u : a) cout << u << ' '; cout << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
    solve();	
}

