#include <iostream>
#include <algorithm>

using namespace std;

#define N_MAX 100
#define M_MAX 100000
#define INF 987654321

int N, M;

int cost[N_MAX + 1][N_MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;

    fill(&cost[0][0], &cost[N][N], INF);

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cost[a][b] = min(cost[a][b], c);
    }

    for (int i = 1; i <= N; i++) {
        cost[i][i] = 0;
    }

    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            for (int k = 1; k <= N; k++) {
                cost[i][k] = min(cost[i][k], cost[i][j] + cost[j][k]);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (cost[i][j] == INF) {
                cout << "0 ";
            } else {
                cout << cost[i][j] << " ";
            }
        }
        cout << "\n";
    }

}