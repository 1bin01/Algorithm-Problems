#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
typedef long long ll;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int N = inf.readInt(2, 200000, "N");
    inf.readEoln();
    for (int i = 0; i < N; i++) {
        int a = inf.readInt(1, 1000000000, "a");
        inf.readSpace();
        int l = inf.readInt(1, N, "l");
        inf.readSpace();
        int r = inf.readInt(l, N, "r");
        inf.readEoln();
        ensuref(l <= r, "error");
    }
    inf.readEof();
    return 0;
}