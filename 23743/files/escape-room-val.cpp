#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
typedef long long ll;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int N = inf.readInt(2, 200000, "N");
    inf.readSpace();
    int M = inf.readInt(1, 100000, "M");
    inf.readEoln();
    for (int i = 0; i < M; i++) {
        int a = inf.readInt(1, N, "a");
        inf.readSpace();
        int b = inf.readInt(1, N, "b");
        inf.readSpace();
        int c = inf.readInt(1, 10000, "c");
        inf.readEoln();
        ensuref(a != b,"error");
    }
    for (int i = 1; i <= N; i++) {
        int t = inf.readInt(1, 10000, "t");
        if (i < N) inf.readSpace();
    }
    inf.readEoln();
    inf.readEof();
    return 0;
}