#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
typedef long long ll;
const int NMAX = 2005;
int H, W, K, Q, A, p[NMAX][NMAX], cnt, x, y;
vector<pair<int, int>> v[NMAX * NMAX];

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> H >> W >> K >> Q;
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++) {
            cin >> A;
            v[A].emplace_back(i, j);
        }
    for (int i = 1; i <= H * W; i++) {
        if (v[i].empty()) continue;
        cnt++;
        int mnx = W + 1;
        int mxx = -1;
        int mny = H + 1;
        int mxy = -1;
        for (auto& [y, x] : v[i]) {
            mnx = min(mnx, x);
            mxx = max(mxx, x);
            mny = min(mny, y);
            mxy = max(mxy, y);
        }
        /* 한 변의 길이가 K보다 크면 K*K 정사각형으로 덮을 수 없음*/
        if (mxx - mnx >= K || mxy - mny >= K) continue;
        int mx = max(mxx - K + 1, 1);
        int Mx = mnx;
        int my = max(mxy - K + 1, 1);
        int My = mny;
        p[my][mx]++;
        p[my][Mx + 1]--;
        p[My + 1][mx]--;
        p[My + 1][Mx + 1]++;
    }
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++) p[i][j] += p[i][j - 1];
    for (int j = 1; j <= W; j++)
        for (int i = 1; i <= H; i++) p[i][j] += p[i - 1][j];

    while (Q--) {
        cin >> y >> x;
        cout << cnt - p[y][x] << '\n';
    }
    return 0;
}