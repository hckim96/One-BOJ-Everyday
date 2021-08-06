#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dh[6] = {0, 0, 0, 0, 1, -1};
int dr[6] = {0, 0, 1, -1, 0, 0};
int dc[6] = {1, -1, 0, 0, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N, H;
    cin >> M >> N >> H;

    vector<vector<vector<int> > > arr(H, vector<vector<int> > (N, vector<int> (M, 0)));
    queue<tuple<int, int, int> > q;

    int unripeCnt = 0;

    for (int h = 0; h < H; ++h) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> arr[h][i][j];
                if (arr[h][i][j] == 0) {
                    ++unripeCnt;
                } else if (arr[h][i][j] == 1) {
                    q.push({h, i, j});
                }
            }
        }
    }

    int answer = 0;

    while (!q.empty() && unripeCnt) {
        int cnt = q.size();
        ++answer;
        while (cnt-- && unripeCnt) {
            auto [fh, fr, fc] = q.front();
            q.pop();

            for (int dir = 0; dir < 6; ++dir) {
                int nh = fh + dh[dir];
                int nr = fr + dr[dir];
                int nc = fc + dc[dir];

                if (nh < 0 || nh >= H || nr < 0 || nr >= N || nc < 0 || nc >= M) {
                    continue;
                }

                if (arr[nh][nr][nc]) {
                    continue;
                }

                --unripeCnt;
                if(unripeCnt == 0) {
                    break;
                }
                arr[nh][nr][nc] = 1;
                q.push({nh, nr, nc});
            }
        }
    }

    if (unripeCnt) {
        cout << "-1\n";
    } else {
        cout << answer << '\n';
    }
}