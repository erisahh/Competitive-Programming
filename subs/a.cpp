#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
	int n, k; cin >> n >> k;
	k -= (n-1);
	cout << k/n << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
    solve();	
}

