#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define all(v) v.begin(), v.end()
typedef long long ll;
const int B = 1 << 22;
int seg[B * 2];
int find(int k){
    int ix = 1;
    while(ix < B){
        seg[ix]--;
        ix <<= 1;
        if(seg[ix] < k) k -= seg[ix++];
    }
    seg[ix]--;
    return ix - B;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    int H = atoi(argv[1]);
    int W = atoi(argv[2]);
    int K = atoi(argv[3]);
    int Q = atoi(argv[4]);
    int h = H;
    int w = W;
    int k = rnd.next(1, min({ h, w, K }));
    int q = rnd.next(1, Q);
    cout << h << ' ' << w << ' ' << k << ' ' << q << '\n';
    
    int cnt = h * w;
    for(int i = 1; i <= cnt; i++) seg[B + i] = 1;
    for(int i = B - 1; i; i--) seg[i] = seg[i * 2] + seg[i * 2 + 1];
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            int a = rnd.next(1, cnt); cnt--;
            cout << find(a);
            if (j < w) cout << ' ';
        }
        cout << '\n';
    }
    while (q--) {
        int y = rnd.next(1, h - k + 1);
        int x = rnd.next(1, w - k + 1);
        cout << y << ' ' << x << '\n';
 
    }
    return 0;
}
