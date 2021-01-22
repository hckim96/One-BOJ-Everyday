#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N_MAX 500
#define INF 987654321

int N, M;
vector<long long> dist(N_MAX + 1, INF);
vector<pair<int, long long> > timeNeeded[N_MAX + 1];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;

        timeNeeded[A].push_back({B, C});
    }

    dist[1] = 0;

    for (int cnt = 0; cnt < N - 1; cnt++) {
        for (int i = 1; i <= N; i++) {
            for (auto p : timeNeeded[i]) {
                if (dist[i] != INF && dist[p.first] > dist[i] + p.second) {
                    dist[p.first] = dist[i] + p.second;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (auto p : timeNeeded[i]) {
            if (dist[i] != INF && dist[p.first] > dist[i] + p.second) {
                cout << "-1\n";
                return 0;
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        if (dist[i] != INF) {
            cout << dist[i] << "\n";
        } else {
            cout << "-1\n";
        }
    }
}