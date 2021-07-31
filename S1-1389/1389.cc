#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int> > adj(N, vector<int> (N, INF));
    for (int i = 0; i < N; ++i) {
        adj[i][i] = 0;
    }

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;

        adj[a][b] = adj[b][a] = 1;
    }

    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            for (int k = 0; k < N; ++k) {
                if (adj[i][k] > adj[i][j] + adj[j][k]) {
                    adj[i][k] = adj[i][j] + adj[j][k];
                }
            }
        }
    }

    // idx, num
    pair<int, int> answer = {-1, INF};

    for (int i = 0; i < N; ++i) {
        int tmp = 0;

        for (int j = 0; j < N; ++j) {
            if (i == j) {
                continue;
            }           

            tmp += adj[i][j];
        }

        if (answer.second > tmp) {
            answer = {i, tmp};
        }
    }

    cout << answer.first + 1 << '\n';
}
