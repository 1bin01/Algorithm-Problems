#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
typedef long long ll;
const int NMAX = 1e5 + 5;
int n, u, v, L[NMAX], d[NMAX], par[NMAX];
vector<int> adj[NMAX];
set<int> s;
vector<tuple<int, int, int>> A;	// (r : upper label, l : lower label, x : lowest node)

void Fail() {
	cout << "NO\n"; exit(0);
}

void dfs(int x, int p, int u) {
	/* extract segment*/
	if (L[x]) {
		if (x > 1) A.emplace_back(u, L[x], p);
		u = L[x];
	}
	/* leaf node*/
	else if (x > 1 && adj[x].size() == 1) A.emplace_back(u, 0, x), d[x] = 1;

	for (int& nx : adj[x])
		if (nx != p) {
			par[nx] = x;
			if (L[x] && L[nx] && L[x] < L[nx]) Fail();	/* invalid input*/
			dfs(nx, x, u); d[x]++;
		}
	return;
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
	}
	else if (L[1] > 0 && L[1] < n) Fail();

	dfs(1, -1, 1);
	sort(all(A));
	for (auto [r, l, x] : A) {
		if (l == r) continue;
		while (L[x] < r) {
			if (--d[x] > 0) break;	/* child를 다 채운 후에 parent 노드를 채우기 시작*/
			for (int& nx : adj[x])	/* child 보다 label이 커야 함*/
				if (nx != par[x]) l = max(l, L[nx]);
			auto it = s.upper_bound(l);
			if (it == s.end() || *it >= r) Fail();
			L[x] = *it; s.erase(it);
			x = par[x];
		}
	}
	if (s.size()) Fail();
	cout << "YES\n";
	for (int i = 1; i <= n; i++) cout << L[i] << ' ';
	return 0;
}