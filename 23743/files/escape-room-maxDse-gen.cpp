#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
typedef long long ll;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    int C = atoi(argv[3]);

    int n = N;
    int m = M;
    cout << n << ' ' << m << '\n';
    for (int i = 1; i < n && m; i++, m--) {
        cout << i << ' ' << i + 1 << ' ' << min(n - i, 9999) << '\n';
    }

    for (int i = 0; i < m; i++) {
        int a = rnd.next(1, n);
        int b = rnd.next(1, n);
        int c = C;
        if (a == b) {
            i--; continue;
        }
        cout << a << ' ' << b << ' ' << c << '\n';
    }
    for (int i = 1; i <= n; i++) {
        int c = C;
        cout << c;
        if (i < n) cout << ' ';
    }
    cout << '\n';
    return 0;
}
