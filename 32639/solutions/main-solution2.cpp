#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
typedef long long ll;
const int NMAX = 1e5 + 5;
int n, u, v, L[NMAX], d[NMAX], par[NMAX], lv[NMAX];
vector<int> adj[NMAX];
set<int> s;
vector<pair<int, int>> V;

void Fail() {
	cout << "NO\n"; exit(0);
}

void go(int x, int p) {
	for(int& nx : adj[x])
		if (nx != p) {
			lv[nx] = lv[x] + 1;
			go(nx, x);
		}
	return;
}

int dfs(int x, int r) {
	if (x != r && L[x]) return L[x];
	int mx = 0;
	for (int& nx : adj[x])
		if(lv[nx] > lv[x]) mx = max(mx, dfs(nx, r));
	mx++;
	if (x == r) {
		if (mx > L[x]) Fail();
	}
	else {
		auto it = s.lower_bound(mx);
		if (it == s.end()) Fail();
		L[x] = *it;
		s.erase(it);
	}
	return L[x];
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) s.emplace(i);
	for (int i = 1; i <= n; i++) {
		cin >> L[i];
		if (L[i]) s.erase(L[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}

	/* L[1] = n */
	if (!L[1]) {
		if (s.find(n) == s.end()) Fail();
		L[1] = n, s.erase(n);
	}//
	else if (L[1] > 0 && L[1] < n) Fail();

	go(1, -1);
	for (int i = 1; i <= n; i++)
		if (L[i]) V.emplace_back(L[i], i);
	sort(all(V));
	for (auto&[l, x] : V) dfs(x, x);
	cout << "YES\n";
	for (int i = 1; i <= n; i++) cout << L[i] << ' ';
	return 0;
}