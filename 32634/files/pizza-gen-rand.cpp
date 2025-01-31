#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
typedef long long ll;
const int NMAX = 2e5 + 5;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    int n = rnd.next(1, N);
    int m = rnd.next(1, M);
    cout << n << ' ' << m << '\n';
    
    for (int i = 0; i < m; i++) {
        int t = rnd.next(1, n);
        int k = rnd.next(1, t);
        cout << t << ' ' << k << '\n';
    }
    return 0;
}