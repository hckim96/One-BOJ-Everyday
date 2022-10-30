N, M = map(int, input().split())
T = [int(input()) for _ in range(N)]

lo = 0
hi = max(T) * M

def check(t):
  ret = 0
  for e in T:
    ret += t // e
  return ret

while lo  + 1 < hi:
  mid = (lo + hi) // 2
  if check(mid) >= M:
    hi = mid
  else:
    lo = mid

print(hi)