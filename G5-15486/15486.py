N = int(input())
T = [0] * N
P = [0] * N
dp = [0] * (N + 1)
for i in range(N):
  T[i], P[i] = map(int, input().split())

for i in range(N):
  if i + 1 <= N:
    dp[i + 1] = max(dp[i + 1], dp[i])
  if i + T[i] <= N:
    dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i])
print(dp[N])
