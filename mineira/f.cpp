#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
void solve(){
	int g; cin >> g;
	string s; cin >> s;
 
	int a = 0;
	map<int,int> f;
	int d = 0, v = 360 / g + (360 % g != 0) ;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'D') a += g;
		else a -= g;

		if(a == 0) continue;
		if(!f[a]) d++;
		f[a]++;
	}
 
	cout << (d >= v ? "S" : "N") << endl;
}
 
signed main(){
	cin.tie(0)->sync_with_stdio(0);
    solve();	
}
