#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
typedef long long ll;
const int NMAX = 2e5 + 5;
ll n, m, p[NMAX], ans, t, k, sum;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    while (m--) {
        cin >> t >> k;
        p[t - k + 1]++; p[t + 1]--;
    }
    for (int i = 1; i <= n; i++) {
        p[i] += p[i - 1];
        sum += p[i];
        if(sum) ans = max(ans, (sum - 1) / i + 1);
    }
    cout << ans;
    return 0;
}