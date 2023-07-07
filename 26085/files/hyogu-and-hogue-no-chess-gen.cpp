#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define all(v) v.begin(), v.end()
typedef long long ll;
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
 
    int n = rnd.next(3, N);
    int m = rnd.next(3, M);
    int c = rnd.next(0, 1);
    cout << n << ' ' << m << '\n';
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << ((i + j) % 2 == c);
            if(j < m) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}