#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, R;
    cin >> N >> M >> R;

    vector<vector<int> > adj(N + 1, vector<int> (N + 1, INF));
    vector<int> itemCnt(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        cin >> itemCnt[i];
    }

    for (int i = 0; i < R; ++i) {
        int n1, n2, w;
        cin >> n1 >> n2 >> w;

        adj[n1][n2] = adj[n2][n1] = w;
    }

    for (int i = 1; i <= N; ++i) {
        adj[i][i] = 0;
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

    vector<int> maxItemCnt(N + 1, 0);

    int answer = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (adj[i][j] <= M) {
                maxItemCnt[i] += itemCnt[j];
            }
        }
        answer = max(answer, maxItemCnt[i]);
    }

    cout << answer << '\n';
}