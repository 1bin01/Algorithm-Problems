#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
typedef long long ll;
const int NMAX = 1e3 + 5;
int n, m, a[NMAX][NMAX], cnt[2];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int find_start_point(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            for(int k = 0; k < 4; k++){
                int ny = i + dy[k];
                int nx = j + dx[k];
                if(ny < 1 || nx < 1 || ny > n || nx > m) continue;
                if(a[i][j] == a[ny][nx]) return 1;
            }
    return 0;
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> a[i][j], cnt[a[i][j]]++;
    if(!find_start_point() || (cnt[0] & 1) || (cnt[1] & 1)) cout << -1;
    else cout << 1;
    return 0;
}
