#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<vector<int> > adj(N + 1, vector<int> (N + 1, INF));

    for (int i = 0; i < K; ++i) {
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

    vector<vector<int> > relation(N + 1, vector<int> (N + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (adj[i][j] != INF) {
                relation[i][j] = -1;
                relation[j][i] = 1;
            }
        }
    }
    
    int S;
    cin >> S;


    while (S--) {
        int a, b;
        cin >> a >> b;
        cout << relation[a][b] << '\n';
    }
}