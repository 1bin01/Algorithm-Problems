#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
typedef long long ll;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int N = inf.readInt(3, 1000, "N");
    inf.readSpace();
    int M = inf.readInt(3, 1000, "M");
    inf.readEoln();
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            int a = inf.readInt(0, 1, "a");
            if(j < M) inf.readSpace();
        }
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}