#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
	string s; cin >> s;
	int n; cin >> n;
	if(n == 1){
		cout << s << endl;
		return;
	}

	char res[s.size()];

	int a = n, j = 0, k = 0, p = 1;
	bool ini = 1, fin = 0;
	//cout << s.size() << endl;
	for(int i = 0; i < s.size(); i++){
		res[j] = s[i];
		//cout << "j " << j << " s[i] " << s[i] << " p " << p << endl;
		if(fin) p = 0;

		if(p) j += 2 * a - 2;
		else j += 2 * (n - a + 1) - 2;
		
		if(!ini && !fin) p ^= 1;

		if(j >= s.size()){
			ini = 0;
			k++;
			if(k == n - 1) fin = 1;
			j = k;
			a--;
			p = 1;
		}
	}
	
	for(int i = 0; i < s.size(); i++){
		cout << res[i];
	}
	cout << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
    solve();	
}

