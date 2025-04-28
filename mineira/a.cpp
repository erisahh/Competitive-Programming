#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mx = 1e3 + 3;

int n, m, t, ci, cj;
vector<string> ar;
int dist[mx][mx];
vector<pair<int,int>> mv = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool pode(int i, int x, int j, int y){
	return i + x < n && i + x >= 0 && j + y < m && j + y >= 0;  
}

void bfs(){
	for(int i = 0; i < mx; i++) {
		for (int j = 0; j < mx; j++) dist[i][j] = -1;
	}
	dist[ci][cj] = 0;
	
	queue<pair<int,int>> q;
	q.push({ci,cj});

	while(!q.empty()){
		auto [i, j] = q.front();
		q.pop();
		
		for(auto [x, y] : mv) {
			if (pode(i, x, j, y) && ar[i + x][j + y] != '#' && dist[i + x][j + y] == -1) {
				if(dist[i][j] + 1 <= t){
					dist[i + x][j + y] = dist[i][j] + 1;
					q.emplace(i + x, j + y);
				}
			}
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << dist[i][j] << ' '; cout << endl;
	}*/
}

void solve(){
	cin >> n >> m >> t >> ci >> cj;
	ci--; cj--;

	int pontos = 0, cont = 0;
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		for (auto c : s) {
			if (c == '.') pontos++;
		}
		ar.push_back(s);
	}

	bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] != -1) cont++;
		}
	}


	int aux = gcd(cont, pontos);

	while (aux != 1) {
		cont /= aux;
		pontos /= aux;
		aux = gcd(cont, pontos);
	}

	cout << cont << ' ' << pontos << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
    solve();	
}

