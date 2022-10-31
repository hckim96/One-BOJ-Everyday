T, W = map(int, input().split())

# t, p
a = [[0 for _ in range(2)] for _ in range(T)]
for t in range(T):
  if int(input()) == 1:
    a[t][0] = 1
  else:
    a[t][1] = 1
# t, w, p
dp = [[[-1 for _ in range(2)] for _ in range(W + 1)] for _ in range(T)]

def f(t, w, p):
  if t == T:
    return 0
  if dp[t][w][p] != -1:
    return dp[t][w][p]
  ret = 0

  if t < T:
    ret = max(ret, f(t + 1, w, p) + a[t][p])
    if w < W:
      ret = max(ret, f(t + 1, w + 1, p ^ 1) + a[t][p ^ 1])
  dp[t][w][p] = ret
  return ret

print(f(0, 0, 0))