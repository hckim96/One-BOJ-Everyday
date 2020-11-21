#include <iostream>
#include <queue>
#include <functional>
#include <tuple>


using namespace std;

#define N_MAX 1000
#define E_MAX 1000
int N, M;
int company[N_MAX] = {0};

// transfer, time
pair<int, int> weight[N_MAX][N_MAX];

struct compare {
    bool operator() (tuple<int, int, int> t1, tuple<int, int, int> t2) { // min heap
        if (get<0>(t1) == get<0>(t2)) {
            return get<1>(t1) > get<1>(t2);
        } else {
            return get<0>(t1) > get<0>(t2);
        }
    }
};

// transferCnt, time
pair<int, int> cost[N_MAX];
void dijkstra() {

    int visited[N_MAX] = {0};
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, compare> pq;
    
    for (int i = 0; i < N; i++) {
        cost[i] = {2 * N_MAX, 10 * E_MAX * N_MAX};
    }
    cost[0].first = 0;
    cost[0].second = 0;

    pq.push({0, 0, 0});

    while (!pq.empty()) {

        int frontTransfer, frontTime, frontNode;
        tie(frontTransfer, frontTime, frontNode) = pq.top();
        pq.pop();
        if (visited[frontNode] == 1) {
            continue;
        }
        
        visited[frontNode] = 1;

        for (int i = 0; i < N; i++) {
            if (weight[frontNode][i].second == 0) {
                continue;
            }

            if (cost[i].first > cost[frontNode].first + weight[frontNode][i].first) {
                cost[i].first = cost[frontNode].first + weight[frontNode][i].first;
                cost[i].second = cost[frontNode].second + weight[frontNode][i].second;
                pq.push({cost[i].first, cost[i].second, i});
            } else if (cost[i].first == cost[frontNode].first + weight[frontNode][i].first) {
                if (cost[i].second > cost[frontNode].second + weight[frontNode][i].second) {
                    cost[i].second = cost[frontNode].second + weight[frontNode][i].second;
                    pq.push({cost[i].first, cost[i].second, i});
                }
            }
        }
    }

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

    cout << cost[M].first << " " << cost[M].second << "\n";
}