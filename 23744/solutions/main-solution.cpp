#include <bits/stdc++.h>
 
using namespace std;
 
#define all(v) v.begin(), v.end()
typedef long long ll;
const int NMAX = 2e5 + 5;
const int inf = 1e9;
int n, a[NMAX], l[NMAX], r[NMAX], q[NMAX], base = 1, ans;
vector<int> seg;
queue<pair<int, int>> que[NMAX];
 
int find(int l, int r) {
	int ret = inf;
	l += base; r += base;
	while (l <= r) {
		if (l & 1) ret = min(ret, seg[l++]);
		if (!(r & 1)) ret = min(ret, seg[r--]);
		l /= 2;
		r /= 2;
	}
	return ret;
}
 
void update(int idx, int v) {
	idx += base;
	seg[idx] = v; idx /= 2;
	while (idx) {
		seg[idx] = min(seg[idx * 2], seg[idx * 2 + 1]);
		idx /= 2;
	}
	return;
}
 
void go() {
	for (int i = 1; i < base * 2; i++) seg[i] = inf;
	for (int i = 1; i <= n; i++) {
		while (que[i].size()) {
			int ix = que[i].front().first;
			if (que[i].front().second == -1) update(ix, inf);
			else update(ix, a[ix]);
			que[i].pop();
		}
		int s = max(1, i - r[i]);
		int e = i - l[i];
		ans = max(ans, a[i] - find(s, e));
 
		s = i + l[i];
		e = i + r[i] + 1;
		if (s <= n) que[s].emplace(i, 1);
		if (e <= n) que[e].emplace(i, -1);
	}
	return;
}
 
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> l[i] >> r[i];
	while (base < n + 1) base *= 2;
	seg.resize(base * 2);
	ans = -2e9;
	go();
	reverse(a + 1, a + n + 1);
	reverse(l + 1, l + n + 1);
	reverse(r + 1, r + n + 1);
	go();
	if (ans < 0) cout << -1;
	else cout << ans;
	return 0;
}
