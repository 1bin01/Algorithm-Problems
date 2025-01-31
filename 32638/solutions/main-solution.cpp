#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
typedef long long ll;
const int NMAX = 2005;
int H, W, K, Q, A, p[NMAX][NMAX], cnt, x, y, mnx[NMAX*NMAX], mxx[NMAX * NMAX], mny[NMAX * NMAX], mxy[NMAX * NMAX];
vector<pair<int, int>> v[NMAX * NMAX];

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> H >> W >> K >> Q;
    memset(mnx, 0x3f, sizeof(mnx));
    memset(mny, 0x3f, sizeof(mny));
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++) {
            cin >> A;
            if (!mxx[A]) cnt++;
            mnx[A] = min(mnx[A], j);
            mxx[A] = max(mxx[A], j);
            mny[A] = min(mny[A], i);
            mxy[A] = max(mxy[A], i);
        }
    for (int i = 1; i <= H * W; i++) {
        if (!mxx[i]) continue;
        /* 한 변의 길이가 K보다 크면 K*K 정사각형으로 덮을 수 없음*/
        if (mxx[i] - mnx[i] >= K || mxy[i] - mny[i] >= K) continue;
        int mx = max(mxx[i] - K + 1, 1);
        int Mx = mnx[i];
        int my = max(mxy[i] - K + 1, 1);
        int My = mny[i];
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