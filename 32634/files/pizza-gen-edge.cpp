#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define all(v) v.begin(), v.end()
typedef long long ll;
const int NMAX = 2e5 + 5;
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    cout << n << ' ' << m << '\n';
    
    for (int i = 0; i < m; i++) {
        int t = rnd.next(1, n);
        int k = rnd.next(1, t);
        cout << t << ' ' << k << '\n';
    }
    return 0;
}