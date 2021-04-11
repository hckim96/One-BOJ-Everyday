#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int dr[5] = {-99, -1, 1, 0, 0};
int dc[5] = {-99, 0, 0, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    // {sharkNumber, leftTime}
    vector<vector<pair<int, int> > > smell(N, vector<pair<int, int> > (N));
    // {r, c, dir, isAlive}
    vector<tuple<int, int, int, bool> > shark(M + 1, {0, 0, 0, false});
    vector<vector<vector<int> > > sharkOrder(M + 1, vector<vector<int> > (5, vector<int> (4)));
    vector<vector<int> > map(N, vector<int> (N, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
            if (map[i][j]) {
                shark[map[i][j]] = {i, j, 0, true};
                smell[i][j] = {map[i][j], K};
            }
        }
    }

    for (int i = 1; i <= M; ++i) {
        cin >> get<2>(shark[i]);
    }

    for (int i = 1; i <= M; ++i) {
        for (int d = 1; d <= 4; ++d) {
            for (int order = 0; order < 4; ++order) {
                cin >> sharkOrder[i][d][order];
            }
        }
    }

    int time = 0;

    while (time < 1000) {
        // 이동

        for (int num = 1; num <= M; ++num) {
            auto [r, c, d, isAlive] = shark[num];
            
            if (!isAlive) {
                continue;
            }

            // nr, nc, nd
            bool canMove = false;

            int nr, nc, nd;
            bool nIsAlive = true;

            for (auto e: sharkOrder[num][d]) {
                nr = r + dr[e];
                nc = c + dc[e];
                if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
                    continue;
                }


                if (smell[nr][nc].second == 0) {
                    canMove = true;
                    nd = e;
                    if (map[nr][nc]) {
                        nIsAlive = false;
                    }
                    break;
                }
            }

            if (!canMove) {
                for (auto e: sharkOrder[num][d]) {
                    nr = r + dr[e];
                    nc = c + dc[e];
                    if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
                        continue;
                    }
                    if (smell[nr][nc].first == num) {
                        canMove = true;
                        nd = e;
                        break;
                    }
                }
            }

            shark[num] = {nr, nc, nd, nIsAlive};
            map[r][c] = 0;
            if (nIsAlive) {
                map[nr][nc] = num;           
            }
        }
        
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (map[i][j]) {
                    ++cnt;
                    smell[i][j] = {map[i][j], K};
                } else if (smell[i][j].second) {
                    --smell[i][j].second;
                }
            }
        }

        ++time;
        if (cnt == 1) {
            cout << time << '\n';
            return 0;
        }
    }

    cout << "-1\n";
}