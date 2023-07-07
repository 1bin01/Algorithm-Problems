#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
typedef long long ll;
struct edge {
	int u, v, c;
	bool operator < (const edge& e) { return c < e.c; }
};
const int NMAX = 2e5 + 5;
int n, m, a, b, c, t, ans, par[NMAX], chk[NMAX];
vector<edge> v;
int find(int x) { return (par[x] == -1) ? x : par[x] = find(par[x]); }

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	while (m--) {
		cin >> a >> b >> c;
		v.push_back({ a, b, c });
	}
	for (int i = 1; i <= n; i++) {
		cin >> t;
		v.push_back({ i, i, t });
	}

	sort(all(v));
	memset(par, -1, sizeof(par));
	for (auto [a, b, c] : v) {
		if (a == b) {
			a = find(a);
			if (!chk[a]) chk[a] = 1, ans += c;
			continue;
		}

		a = find(a); b = find(b);
		if (a == b || chk[a] && chk[b]) continue;
		par[b] = a; ans += c; chk[a] |= chk[b];
	}
	cout << ans;
	return 0;
}
