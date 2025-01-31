import sys; input = sys.stdin.readline
MIS = lambda: map(int, input().split())
II = lambda: int(input())
IS = lambda: input().strip()

N, M, K, Q = MIS()
arr = [list(MIS()) for _ in range(N)]

V = N*M
chk = [[0, N+1, -1, M+1, -1] for _ in range(V)]
for i in range(N):
    for j in range(M):
        cur = arr[i][j]-1
        chk[cur][0] = 1
        chk[cur][1] = min(chk[cur][1], i)
        chk[cur][2] = max(chk[cur][2], i)
        chk[cur][3] = min(chk[cur][3], j)
        chk[cur][4] = max(chk[cur][4], j)

res = 0
pv = [[0]*(M+1) for _ in range(N+1)]
for i in range(V):
    if not chk[i][0]: continue
    res += 1
    u, d, l, r = chk[i][1:]
    if d-u+1 > K or r-l+1 > K: continue
    sy, sx = max(0, d-K+1), max(0, r-K+1)
    ey, ex = u+1, l+1
    pv[sy][sx] -= 1; pv[ey][ex] -= 1
    pv[sy][ex] += 1; pv[ey][sx] += 1

pf = [[0]*(M+1)]
for i in range(N):
    cur = [0]
    for j in range(M):
        cur.append(cur[-1]+pv[i][j])
    for j in range(M+1):
        cur[j] += pf[-1][j]
    pf.append(cur)

for _ in range(Q):
    y, x = MIS()
    print(res+pf[y][x])