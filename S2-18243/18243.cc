#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, K;
    cin >> N >> K;

    vector<vector<int> > dist(N + 1, vector<int> (N + 1, 1e9));
    while (K--) {
        int u, v;
        cin >> u >> v;
        dist[u][v] = dist[v][u] = 1;
    }
    for (int i = 1; i <= N; ++i) {
        dist[i][i] = 0;
    }

    for (int j = 1; j <= N; ++j) {
        for (int i = 1; i <= N; ++i) {
            for (int k = 1; k <= N; ++k) {
                if (dist[i][k] > dist[i][j] + dist[j][k]) {
                    dist[i][k] = dist[i][j] + dist[j][k];
                }
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            if (dist[i][j] > 6) {
                cout << "Big World!\n";
                return 0;
            }
        }
    }
    cout << "Small World!\n";
}