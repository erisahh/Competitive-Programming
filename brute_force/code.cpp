#include <bits/stdc++.h>
#define int long long
#define ii pair<int,int>
 
using namespace std;
 
void solve(){
	int N, X; cin >> N >> X;
	vector<int> a(N+1);
	map<int,int> f;
	for(int i = 1; i < N+1; i++){
		cin >> a[i];
		f[a[i]] = i;
	}
 
	int p1 = -1, p2 = -1;
	for(int i = 1; i < N+1; i++){
		int aux = X-a[i];
		if(f[aux]){
			p1 = i; p2 = f[aux]; break;
		}
	}
	
	if(p1 == -1) cout << "IMPOSSIBLE\n";
	else cout << p1 << ' ' << p2 << endl;
}
 
signed main(){
	cin.tie(0)->sync_with_stdio(0);
    solve();	
}
