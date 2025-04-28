#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	int v = 1;

	if(s[0] == '.'){
		cout << -1 << endl;
		return;
	}

	int res = 0, count = 0;
	for(int i = 0; i < n - 1; i++){
		if(s[i + 1] == '.'){
			if(count == 0) res++;
			count++;
		}else{
			if(count != 0){
				int soma = v + 1;
				if(soma <= count){
					cout << -1 << endl;
					return;
				}
				count = 0;
				v = 0;
			}
			v++;
		}
	}

	cout << res << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
    solve();	
}

