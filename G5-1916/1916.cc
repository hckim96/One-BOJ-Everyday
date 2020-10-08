#include <iostream>
#include <queue>

#define WEIGHTMAX 987654321
using namespace std;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

int N, M, A, B;
priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;


int weight[1001][1001] = {};

// from start to some node
int minDistance[1001] = {};

int main() {
    

    cin >> N >> M;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (i == j) {
                weight[i][j] = 0;
            }
            weight[i][j] = WEIGHTMAX; // 연결 안되어 있다는 뜻
        }
        minDistance[i] = WEIGHTMAX; // 첫 비교 시 작은걸 하려고 오버플로우 고려해서 값 설정해야됨
    }

    int x, y, z;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> z;
        weight[x][y] = weight[x][y] > z ? z: weight[x][y]; // 같은게 들어오면 그냥 작은거 하나만 남김
    }

    cin >> A >> B;

    pq.push({A, 0});

    while(!pq.empty()) {
        int city = pq.top().first;
        int distance = pq.top().second;
        pq.pop();

        for (int i = 1; i <= N; i++) {
            if (weight[city][i] != WEIGHTMAX && minDistance[i] > distance + weight[city][i]) {
                minDistance[i] = distance + weight[city][i];
                pq.push({i, minDistance[i]});
            }
        }
        

    }

    cout << minDistance[B] << "\n";

}