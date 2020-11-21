#include <iostream>
#include <queue>
#include <functional>

using namespace std;

#define N_MAX 1000
#define E_MAX 1000
int N, M;
int company[N_MAX] = {0};

// transfer, time
pair<int, int> weight[N_MAX][N_MAX];



// transferCnt, time
pair<int, int> cost[N_MAX];
void dijkstra() {
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> company[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int tmp;
            cin >> tmp;
            int transfer = (company[i] != company[j] ? 1 : 0);
            weight[i][j] = {transfer, tmp};
        }
    }
    

    dijkstra();

    for (int i = 0; i < N; i++) {
        if (adjacency[M][i] > 0) {
            if (cost[M].second > cost[i].second + adjacency[i][M]) {
                cost[M].second = cost[i].second + adjacency[i][M];
            }
        }
    }
    cout << cost[M].first << " " << cost[M].second << "\n";
}