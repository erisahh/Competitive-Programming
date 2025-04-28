#include <bits/stdc++.h>
#define int long long
#define T pair<int, double>

using namespace std;

const double PI = acos(-1);

void solve(){

	int angulo, n; cin >> angulo >> n;
	double ang = angulo * PI / 180;
	double tang = tan(ang);

	int aux = n;
	vector<T> v;
	while (aux--) {
		int x, h; cin >> x >> h;
		double ca = h / tang;
		v.emplace_back(x, double(x + ca));
	}

	sort(v.begin(), v.end());
	double L = v[0].first, R = v[0].second; 
	double ans = R - L;

	for (int i = 1; i < n; i++) {
		auto [l, r] = v[i];
		if (r <= R) continue;
		if (l >= R) ans += (r - l);
		else ans += (r - R);	
		R = r;
		/*if (l >= R) {
			ans += (R - l);
		}
		else { // l < R
			if (r > R) {
				ans += (r - R); 
			}
		}
		R = r;*/
	}
	cout << ans << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cout << setprecision(10) << fixed; 
    solve();	
}

