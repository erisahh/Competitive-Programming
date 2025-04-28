#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
	string s; cin >> s;
	int n; cin >> n;
	int a = n;
	int i = 0, j = 0, k = 0;
	
	if(n == 1){
		cout << s << endl;
		return;
	}

	vector<vector<char>>  m(n, (vector<char> (s.size())));
	while(i < s.size()){
		m[j][k] = s[i];
		k += a + 1;
		i++;
		if(k > s.size()){
			j++;
			a--;
			k = j;
		}
	}

	for(int p = 0; p < n; p++){
		for(int q = 0; q < s.size(); q++){
			cout << m[p][q] << " ";
		}
		cout << endl;
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
    solve();	
}

