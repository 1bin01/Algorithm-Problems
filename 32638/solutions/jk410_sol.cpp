#include <bits/stdc++.h>
using namespace std;
const int MAX=2000;
int H,W,K,Q;
int LR[MAX*MAX+1],RR[MAX*MAX+1],LC[MAX*MAX+1],RC[MAX*MAX+1];
int Ans[MAX+2][MAX+2];
int Cnt;
void add(int lr,int lc,int rr,int rc) {
    lr=max(lr,1);
    lc=max(lc,1);
    Ans[lr][lc]++;
    Ans[rr+1][lc]--;
    Ans[lr][rc+1]--;
    Ans[rr+1][rc+1]++;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>H>>W>>K>>Q;
    fill(LR+1,LR+MAX*MAX+1,MAX+1);
    fill(LC+1,LC+MAX*MAX+1,MAX+1);
    for (int i=1; i<=H; i++) {
        for (int j=1; j<=W; j++) {
            int x;
            cin>>x;
            LR[x]=min(LR[x],i);
            RR[x]=max(RR[x],i);
            LC[x]=min(LC[x],j);
            RC[x]=max(RC[x],j);
        }
    }
    for (int i=1; i<=H*W; i++) {
        if (!RR[i])
            continue;
        Cnt++;
        if (RR[i]-LR[i]<K&&RC[i]-LC[i]<K)
            add(RR[i]-K+1,RC[i]-K+1,LR[i],LC[i]);
    }
    for (int i=1; i<=H; i++) {
        for (int j=1; j<=W; j++)
            Ans[i][j]+=Ans[i-1][j]+Ans[i][j-1]-Ans[i-1][j-1];
    }
    while (Q--) {
        int r,c;
        cin>>r>>c;
        cout<<Cnt-Ans[r][c]<<"\n";
    }
    return 0;
}
