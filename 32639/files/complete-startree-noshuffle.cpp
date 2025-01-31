#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define all(v) v.begin(), v.end()
typedef long long ll;
const int NMAX = 1e5 + 5;
int n, d[NMAX], par[NMAX], L[NMAX];
vector<pair<int, int>> Edge;
vector<int> adj[NMAX];
 
void dfs(int x, int p) {
    for (int& nx : adj[x])
        if (nx != p) {
            par[nx] = x; d[x]++;
            dfs(nx, x);
        }
    return;
}
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int N = atoi(argv[1]);

    int p = atoi(argv[2]); 
    int q = atoi(argv[3]); // p/q -> no color

    int root_label = atoi(argv[4]); //root_label colored?
    n = rnd.next(N, N);
    cout << n << '\n';
 
    // generate tree
    
    for (int i = 2; i <= n; i++) Edge.push_back({1, i});
    for (int i = 1; i <= n; i++) L[i] = N+1-i;
    
    if (!root_label) L[1] = 0;
    for (int i = 2; i <= n; i++)
        if (p < rnd.next(1, q)) L[i] = 0;

    // output

    for (int i = 1; i <= n; i++) {
        cout << L[i];
        if (i < n) cout << ' ';
    }
    cout << '\n';
    for (auto& [a, b] : Edge) cout << a << ' ' << b << '\n';
    return 0;
}
