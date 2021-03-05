#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int> > adj(N + 1, vector<int> (N + 1, INF));

    for (int i = 0; i < M; ++i) {
      int a, b;
      cin >> a >> b;
      adj[a][b] = 1;
    }

    for (int j = 1; j <= N; ++j) {
      for (int i = 1; i <= N; ++i) {
        for (int k = 1; k <= N; ++k) {
          if (adj[i][k] > adj[i][j] + adj[j][k]) {
              adj[i][k] = adj[i][j] + adj[j][k];
          }
        }
      }
    }

    vector<int> cnt(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (adj[i][j] != INF) {
                ++cnt[i];
                ++cnt[j];
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
      cout << N - 1 - cnt[i] << '\n';
    }
}