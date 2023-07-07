#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
typedef long long ll;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int N = atoi(argv[1]);
    int A = atoi(argv[2]);
    int D = atoi(argv[3]);

    int n = rnd.next(2, N);
    cout << n << '\n';
    for (int i = 0; i < n; i++) {
        int a = rnd.next(1, A);
        int l = rnd.next(1, min(n, D));
        int r = rnd.next(l, min(n, D));
        cout << a << ' ' << l << ' ' << r << '\n';
    }
    return 0;
}
    