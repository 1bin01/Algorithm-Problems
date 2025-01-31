#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
typedef long long ll;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int N = inf.readInt(1, 200000, "N");
    inf.readSpace();
    int M = inf.readInt(1, 200000, "M");
    inf.readEoln();
    for(int i = 0; i < M; i++){
        int t = inf.readInt(1, N, "t_i");
        inf.readSpace();
        int k = inf.readInt(1, t, "k_i");
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}