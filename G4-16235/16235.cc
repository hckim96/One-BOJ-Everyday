#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define N_MAX 10

int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

pair<int, vector<int> > map[N_MAX + 1][N_MAX + 1];
int A[N_MAX + 1][N_MAX + 1];

int N, M, K;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            map[i][j].first = 5;
        }
    }

    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        map[x][y].second.push_back(z);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            sort(map[i][j].second.begin(), map[i][j].second.end(), less<int>());
        }
    }
    while (K--) {
        vector<pair<int, int> > reproduce;
        // 봄 여
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (!map[i][j].second.empty()) {
                    for (auto it = map[i][j].second.rbegin(); it != map[i][j].second.rend(); it++) {
                        if (map[i][j].first >= *it) {
                            map[i][j].first -= *it;
                            (*it)++;
                            if (*it % 5 == 0) {
                                for (int dir = 0; dir < 8; dir++) {
                                    int nr, nc;
                                    nr = i + dr[dir];
                                    nc = j + dc[dir];

                                    if (nr < 1 || nr > N || nc < 1 || nc > N) {
                                        continue;
                                    }
                                    reproduce.push_back({nr, nc});
                                }
                            }
                        } else {
                            while (it != map[i][j].second.rend()) {
                                map[i][j].first += *it / 2;
                                // map[i][j].second.erase(it++);
                                map[i][j].second.erase((it.base() - 1));
                                it++;
                            }
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                map[i][j].first += A[i][j];
            }
        }
        for (auto it = reproduce.begin(); it != reproduce.end(); it++) {
            auto [x, y] = *it;
            map[x][y].second.push_back(1);
        }
    }

    int ret = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!map[i][j].second.empty()) {
                ret += map[i][j].second.size();
            }
        }
    }

    cout << ret << "\n";

}