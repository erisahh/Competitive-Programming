#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
	cout << setprecision(12) << fixed;
	double r1, r2, r3; cin >> r1 >> r2 >> r3;
	int n, q; cin >> n >> q;

	double pi = 2 * acos(0.0); 

	while (q--) {
		int c1, l1; cin >> c1 >> l1;
		int c2, l2; cin >> c2 >> l2;

		if (c1 > c2) {
			swap(c1, c2); swap(l1, l2);
		}

		int aux = min(n - (l2 - l1), l2 - l1);
	
		double raio1, raio2;
		if (c1 == 1) raio1 = r1;
		if (c1 == 2) raio1 = r2;
		if (c1 == 3) raio1 = r3;

		if (c2 == 1) raio2 = r1;
		if (c2 == 2) raio2 = r2;
		if (c2 == 3) raio2 = r3;

		// ((2 * pi * raio) / n) * (aux)
	
		double dist1 = ((2.0 * pi * raio1) / (double)n) * double(aux);
		double dist2 = raio2 - raio1;
		double ans1 = dist1 + dist2;
		cout << "ans1 antes = " << ans1 << endl;

		double dist3 = ((2.0 * pi * r1) / (double)n) * double(aux);
		double dist4 = (raio2 - r1) + (raio1 - r1);
		double ans2 = dist3 + dist4;
		cout << "ans2 antes = " << ans2 << endl;

		cout << min(ans1, ans2) << endl;
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
    solve();	
}

