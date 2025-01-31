#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
	fastio;
	int n, m, k, q; cin >> n >> m >> k >> q;
	vector v(n + 1, vector(m + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> v[i][j];
	}

	vector dp(n * m + 1, array{ n + 1, 0, m + 1, 0 });
	auto update = [&](int i, int x, int y) {
		dp[i][0] = min(dp[i][0], x);
		dp[i][1] = max(dp[i][1], x);
		dp[i][2] = min(dp[i][2], y);
		dp[i][3] = max(dp[i][3], y);
	};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) update(v[i][j], i, j);
	}

	vector p(n + 2, vector(m + 2, 0));
	int cnt = 0;
	for (int i = 1; i <= n * m; i++) {
		auto [a, b, c, d] = dp[i];
		if (a == n + 1) continue;
		cnt++;
		b = max(b - k + 1, 1);
		d = max(d - k + 1, 1);
		if (a < b || c < d) continue;
		p[b][d]++;
		p[b][c + 1]--;
		p[a + 1][d]--;
		p[a + 1][c + 1]++;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int val = p[i][j - 1] + p[i - 1][j] - p[i - 1][j - 1];
			p[i][j] += val;
		}
	}

	while (q--) {
		int a, b; cin >> a >> b;
		cout << cnt - p[a][b] << '\n';
	}
}