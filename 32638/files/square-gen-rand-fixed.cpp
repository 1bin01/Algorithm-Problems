#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define all(v) v.begin(), v.end()
typedef long long ll;
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    int H = atoi(argv[1]);
    int W = atoi(argv[2]);
    int K = atoi(argv[3]);
    int Q = atoi(argv[4]);
    int h = rnd.next(1, H);
    int w = rnd.next(1, W);
    int k = rnd.next(1, min({ h, w, K }));
    int q = rnd.next(1, Q);
    h = H; w = W; k = min({h, w, K}); q = Q;
    cout << h << ' ' << w << ' ' << k << ' ' << q << '\n';
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            int a = rnd.next(1, h * w);
            cout << a;
            if (j < w) cout << ' ';
        }
        cout << '\n';
    }
    while (q--) {
        int y = rnd.next(1, h - k + 1);
        int x = rnd.next(1, w - k + 1);
        cout << y << ' ' << x << '\n';
 
    }
    return 0;
}