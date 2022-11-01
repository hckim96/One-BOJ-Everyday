import math
N, M = map(int, input().split())

a = [[0] * M for _ in range(N)]

for i in range(N):
  s = input()
  for j in range(M):
    a[i][j] = int(s[j])

ans = -1

def isSqr(num):
  sqrt = int(math.sqrt(num))
  if sqrt * sqrt == num: return True
  return False
def f(cur, d, curVal):
  global ans
  r, c = cur
  dr, dc = d

  curVal *= 10
  curVal += a[r][c]

  if isSqr(curVal): ans = max(ans, curVal)

  nr = r + dr
  nc = c + dc
  if nr < 0 or nr >= N or nc < 0 or nc >= M: return
  f((nr, nc), d, curVal)

  
for i in range(N):
  for j in range(M):
    if isSqr(a[i][j]): ans = max(ans, a[i][j])
    for ii in range(N):
      for jj in range(M):
        if i == ii and j == jj: continue
        f((i, j), (ii - i, jj - j), 0)

print(ans)
