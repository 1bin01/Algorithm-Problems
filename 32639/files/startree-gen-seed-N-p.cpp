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
    n = rnd.next(2, N);
    cout << n << '\n';

    // generate tree
    int X = rnd.next(1, n);
    for (int i = 1; i <= n; i++)
        if (i != X) Edge.emplace_back(X, i);
    vector<int> perm(n + 1);
    for (int i = 1; i <= n; i++) perm[i] = i;
    random_device rd;
    mt19937 g(rd());
    shuffle(perm.begin() + 1, perm.end(), g);
    shuffle(all(Edge), g);
    for (auto& [a, b] : Edge) a = perm[a], b = perm[b];

    for (auto& [a, b] : Edge) {
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs(1, -1);
    vector<int> V;
    for (int i = 1; i <= n; i++)
        if (!d[i]) V.emplace_back(i);
    for (int i = 1; i <= n; i++) {
        int ix = rnd.next(0, (int)V.size() - 1);
        swap(V[ix], V[(int)V.size() - 1]);
        int x = V.back();
        L[x] = i;
        V.pop_back();
        if (x > 1) {
            if (--d[par[x]] == 0) V.emplace_back(par[x]);
        }
    }
    for (int i = 1; i <= n; i++)
        if (rnd.next(0, p)) L[i] = 0;
    for (int i = 1; i <= n; i++) {
        cout << L[i];
        if (i < n) cout << ' ';
    }
    cout << '\n';
    for (auto& [a, b] : Edge) cout << a << ' ' << b << '\n';
    return 0;
}