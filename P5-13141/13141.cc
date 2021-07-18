#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define INF 987654321

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<tuple<int, int, int> > edge;
    vector<vector<int> > dist(N + 1, vector<int> (N + 1, INF));


    for (int i = 0; i < M; ++i) {
        int n1, n2, w;

        cin >> n1 >> n2 >> w;

        edge.push_back({n1, n2, w});
        dist[n1][n2] = min(dist[n1][n2], w);
        dist[n2][n1] = min(dist[n2][n1], w);
    }

    for (int i = 1; i <= N; ++i) {
        if (dist[i][i] == INF) {
            dist[i][i] = 0;
        }
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

    double answer = INF;

    for (int i = 1; i <= N; ++i) {
        double tmp = 0;
        for (auto [n1, n2, w]: edge) {
            if (abs(dist[i][n1] - dist[i][n2]) < w) {
                tmp = max(tmp, double(max(dist[i][n1], dist[i][n2]) + (double)(w - abs(dist[i][n1] - dist[i][n2])) / 2));

            } else {
                tmp = max(tmp, (double)max(dist[i][n1], dist[i][n2]));
            }
        }

        answer = min(answer, tmp);
    }

    cout.precision(1);

    cout << fixed << answer << '\n';
}