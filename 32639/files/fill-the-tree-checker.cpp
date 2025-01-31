#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
const int NMAX = 1e5 + 5;
int n, u, v, L[NMAX], inL[NMAX], used[NMAX];
vector<int> adj[NMAX];

void dfs(int x, int p) {
    if(inL[x] && L[x] != inL[x]) quitf(_wa, "wrong answer!");   /* input에서 이미 labeling이 되어 있는 경우*/
    if(x > 1 && L[x] >= L[p]) quitf(_wa, "wrong answer!");   /* 자식 label이 부모 label보다 크거나 같은 경우*/
    used[L[x]] = 1;
    for (int& nx : adj[x])
        if (nx != p) dfs(nx, x);
    return;
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    
    /* get input*/
    n = inf.readInt();
    for (int i = 1; i <= n; i++) inL[i] = inf.readInt();
    for (int i = 0; i < n - 1; i++) {
        u = inf.readInt();
        v = inf.readInt();
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    string answer = ans.readString();
    string output = ouf.readString();
    if(answer != output) quitf(_wa, "answer is %d, output is = %d\n", answer, output);
    if(answer == "NO") quitf(_ok, "ac");

    for (int i = 1; i <= n; i++) L[i] = ouf.readInt(0, n);
    dfs(1, -1);
    for(int i = 1; i <= n; i++) /* 모든 label을 한 번씩 사용하지 않은 경우*/
        if(!used[i]) quitf(_wa, "wrong answer!");
    quitf(_ok, "ac");
    return 0;
}