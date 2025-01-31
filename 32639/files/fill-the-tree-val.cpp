#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
typedef long long ll;
int chk[100001], u, v, par[100001];
int find(int x) { return par[x] == -1 ? x : par[x] = find(par[x]); }

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int N = inf.readInt(2, 100000, "N");
    inf.readEoln();
    for (int i = 1; i <= N; i++) {
        int l = inf.readInt(0, N, "label");
        ensure(!l || !chk[l]);
        chk[l] = 1;
        if(i < N) inf.readSpace();
    }
    inf.readEoln();

    for (int i = 1; i <= N; i++) par[i] = -1;
    for (int i = 0; i < N - 1; i++) {
        u = inf.readInt(1, N, "u");
        inf.readSpace();
        v = inf.readInt(1, N, "v");
        inf.readEoln();
        u = find(u); v = find(v);
        ensure(u != v);
        par[v] = u;
    }
    inf.readEof();
    return 0;
}