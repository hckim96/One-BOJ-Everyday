#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int INF = 987654321;

    int TC;
    cin >> TC;

    while (TC--) {
        int N, M, K;
        cin >> N >> M >> K;

        const int S = 1;
        const int E = N;

        vector<vector<tuple<int, int, int> > > adj(N + 1);
        vector<vector<int> > minTime(N + 1, vector<int> (M + 1, INF));

        for (int i = 0; i < K; ++i) {
            int u, v, c, d;
            cin >> u >> v >> c >> d;
            adj[u].push_back({v, c, d});
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<tuple<int, int, int> > > pq;
        minTime[S][0] = 0;
        pq.push({minTime[S][0], S, 0});

        while (!pq.empty()) {
            auto [t, n, c] = pq.top();
            pq.pop();

            if (n == E) {
                break;
            }

            if (minTime[n][c] < t) {
                continue;
            }

            for (auto [nv, nc, nd]: adj[n]) {
                int nnc = c + nc;
                int nt = t + nd;
                if (nnc > M) {
                    continue;
                }

                if (minTime[nv][nnc] > nt) {
                    for (int i = nnc + 1; i <= M; ++i) {
                        if (minTime[nv][i] > nt) {
                            minTime[nv][i] = nt;
                        } else {
                            break;
                        }
                    }
                    minTime[nv][nnc] = nt;
                    pq.push({minTime[nv][nnc], nv, nnc});
                }
            }
        }

        int answer = INF;
        for (int i = 1; i <= M; ++i) {
            answer = min(answer, minTime[E][i]);
        }

        if (answer == INF) {
            cout << "Poor KCM\n";
        } else {
            cout << answer << '\n';
        }
    }
    
}