#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define all(v) v.begin(), v.end()
typedef long long ll;
int cnt[2]; 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);

    int n = rnd.next(N, N);
    int m = rnd.next(M, M);
    cnt[0] = rnd.next(2, n * m - 2);
    cnt[1] = n * m - cnt[0];
    if(cnt[0] & 1) cnt[0]--, cnt[1]++;
    
    cout << n << ' ' << m << '\n';
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int a = rnd.next(0, 1);
            if(!cnt[a]) a ^= 1;
            cnt[a]--;
            cout << a;
            if(j < m) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}