#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define N_MAX 10

int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

// age cnt
vector<pair<int, int> > tree[N_MAX + 1][N_MAX + 1];
int map[N_MAX + 1][N_MAX + 1];
int A[N_MAX + 1][N_MAX + 1];

int N, M, K;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            map[i][j] = 5;
        }
    }

    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        tree[x][y].push_back({z, 1});
    }

    while (K--) {
        int reproduce[N_MAX + 1][N_MAX + 1] = {0};

        // 봄 여 번식 저장
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (!tree[i][j].empty()) {
                    for (auto it = tree[i][j].rbegin(); it != tree[i][j].rend(); it++) {
                        auto [age, cnt] = *it;

                        if (map[i][j] >= age * cnt) {
                            map[i][j] -= age * cnt;
                            it -> first++;

                            if (it -> first % 5 == 0) {
                                for (int dir = 0; dir < 8; dir++) {
                                    int nr, nc;
                                    nr = i + dr[dir];
                                    nc = j + dc[dir];

                                    if (nr < 1 || nr > N || nc < 1 || nc > N) {
                                        continue;
                                    }
                                    reproduce[nr][nc] += it -> second;
                                }
                            }
                        } else {
                            int canLive = map[i][j] / age;
                            if (canLive > 0) {
                                int die = cnt - canLive;

                                map[i][j] -= age * canLive;
                                map[i][j] += (age / 2) * die;
                                it -> first++;
                                it -> second = canLive;
                                it++;
                            }
                            while (it != tree[i][j].rend()) {
                                map[i][j] += (it -> first / 2) * it -> second;
                                auto nit = decltype(it){tree[i][j].erase((++it).base())};
                                it = nit;
                            }
                            break;
                        }
                    }
                }
            }
        }

        // 번식, 겨
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                tree[i][j].push_back({1, reproduce[i][j]});
                map[i][j] += A[i][j];
            }
        }
    }

    int ret = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!tree[i][j].empty()) {
                for (auto it = tree[i][j].begin(); it != tree[i][j].end(); it++) {
                    ret += it -> second;
                }
            }
        }
    }

    cout << ret << "\n";

}