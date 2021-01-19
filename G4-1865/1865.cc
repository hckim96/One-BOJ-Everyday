#include <iostream>
#include <vector>

using namespace std;

#define N_MAX 500
#define INF 987654321

int TC;
int N, M, W;
int S, E, T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> TC;

    while (TC--) {
        cin >> N >> M >> W;

        vector<vector<pair<int, int> > > adjacency(N);

        for (int i = 0; i < M; i++) {
            cin >> S >> E >> T;
            adjacency[S - 1].push_back({E - 1, T});
            adjacency[E - 1].push_back({S - 1, T});
        }

        for (int i = 0; i < W; i++) {
            cin >> S >> E >> T;
            adjacency[S - 1].push_back({E - 1, -T});
        }


        // Bellman–Ford algorithm
        vector<int> dist(N, INF);
        dist[0] = 0;
        for (int l = 0; l < N - 1; l++) {
            for (int i = 0; i < N; i++) {
                for (auto p : adjacency[i]) {
                    if (dist[p.first] > dist[i] + p.second) {
                        dist[p.first] = dist[i] + p.second;
                    }
                }
            }
        }

        // check for negative cycle
        bool isYes = false;
        for (int i = 0; i < N; i++) {
            if (isYes) {
                break;
            }
            for (auto p : adjacency[i]) {
                if (dist[p.first] > dist[i] + p.second) {
                    isYes = true;
                    break;
                }
            }
        }

        if (isYes) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}