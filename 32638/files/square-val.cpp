#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
typedef long long ll;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int H = inf.readInt(1, 2000, "H");
    inf.readSpace();
    int W = inf.readInt(1, 2000, "W");
    inf.readSpace();
    int K = inf.readInt(1, min(H, W), "K");
    inf.readSpace();
    int Q = inf.readInt(1, 300000, "Q");
    inf.readEoln();
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int a = inf.readInt(1, H*W, "A_ij");
            if (j < W - 1) inf.readSpace();
        }
        inf.readEoln();
    }
    while (Q--) {
        int y = inf.readInt(1, H - K + 1, "y");
        inf.readSpace();
        int x = inf.readInt(1, W - K + 1, "x");
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}