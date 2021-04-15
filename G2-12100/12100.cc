#include <iostream>
#include <vector>

using namespace std;

int answer = 0;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

void f(vector<vector<int> > arr, int dir, int cnt) {

    vector<vector<bool> > combined(arr.size(), vector<bool> (arr.size(), false));

    if (dir == 0) {
        for (int c = arr.size() - 2; c >= 0; --c) {
            for (int r = 0; r < arr.size(); ++r) {
                if (!arr[r][c]) {
                    continue;
                }

                int i = 1;
                while (true) {
                    int nr = r + dr[dir] * i;
                    int nc = c + dc[dir] * i;

                    if (nr < 0 || nr >= arr.size() || nc < 0 || nc >= arr.size()) {
                        break;
                    }

                    if (arr[nr][nc]) {
                        break;
                    }

                    ++i;
                }

                int nr = r + dr[dir] * i;
                int nc = c + dc[dir] * i;

                if (nr < 0 || nr >= arr.size() || nc < 0 || nc >= arr.size()) {
                    nr -= dr[dir];
                    nc -= dc[dir];

                    swap(arr[nr][nc], arr[r][c]);
                } else {
                    if (arr[r][c] == arr[nr][nc] && !combined[nr][nc]) {
                        combined[nr][nc] = true;
                        arr[nr][nc] *= 2;
                        arr[r][c] = 0;
                    } else {
                        nr -= dr[dir];
                        nc -= dc[dir];
                        swap(arr[nr][nc], arr[r][c]);
                    }
                }
            }
        }
    } else if (dir == 1) {
        for (int c = 1; c < arr.size(); ++c) {
            for (int r = 0; r < arr.size(); ++r) {
                if (!arr[r][c]) {
                    continue;
                }

                int i = 1;
                while (true) {
                    int nr = r + dr[dir] * i;
                    int nc = c + dc[dir] * i;

                    if (nr < 0 || nr >= arr.size() || nc < 0 || nc >= arr.size()) {
                        break;
                    }

                    if (arr[nr][nc]) {
                        break;
                    }

                    ++i;
                }

                int nr = r + dr[dir] * i;
                int nc = c + dc[dir] * i;

                if (nr < 0 || nr >= arr.size() || nc < 0 || nc >= arr.size()) {
                    nr -= dr[dir];
                    nc -= dc[dir];

                    swap(arr[nr][nc], arr[r][c]);
                } else {
                    if (arr[r][c] == arr[nr][nc] && !combined[nr][nc]) {
                        combined[nr][nc] = true;
                        arr[nr][nc] *= 2;
                        arr[r][c] = 0;
                    } else {
                        nr -= dr[dir];
                        nc -= dc[dir];
                        swap(arr[nr][nc], arr[r][c]);
                    }
                }
            }
        }
    } else if (dir == 2) {
        for (int r = arr.size() - 2; r >= 0; --r) {
            for (int c = 0; c < arr.size(); ++c) {
                if (!arr[r][c]) {
                    continue;
                }

                int i = 1;
                while (true) {
                    int nr = r + dr[dir] * i;
                    int nc = c + dc[dir] * i;

                    if (nr < 0 || nr >= arr.size() || nc < 0 || nc >= arr.size()) {
                        break;
                    }

                    if (arr[nr][nc]) {
                        break;
                    }

                    ++i;
                }

                int nr = r + dr[dir] * i;
                int nc = c + dc[dir] * i;

                if (nr < 0 || nr >= arr.size() || nc < 0 || nc >= arr.size()) {
                    nr -= dr[dir];
                    nc -= dc[dir];

                    swap(arr[nr][nc], arr[r][c]);
                } else {
                    if (arr[r][c] == arr[nr][nc] && !combined[nr][nc]) {
                        combined[nr][nc] = true;
                        arr[nr][nc] *= 2;
                        arr[r][c] = 0;
                    } else {
                        nr -= dr[dir];
                        nc -= dc[dir];
                        swap(arr[nr][nc], arr[r][c]);
                    }
                }
            }
        }
    } else {
        for (int r = 1; r < arr.size(); ++r) {
            for (int c = 0; c < arr.size(); ++c) {
                if (!arr[r][c]) {
                    continue;
                }

                int i = 1;
                while (true) {
                    int nr = r + dr[dir] * i;
                    int nc = c + dc[dir] * i;

                    if (nr < 0 || nr >= arr.size() || nc < 0 || nc >= arr.size()) {
                        break;
                    }

                    if (arr[nr][nc]) {
                        break;
                    }

                    ++i;
                }

                int nr = r + dr[dir] * i;
                int nc = c + dc[dir] * i;

                if (nr < 0 || nr >= arr.size() || nc < 0 || nc >= arr.size()) {
                    nr -= dr[dir];
                    nc -= dc[dir];

                    swap(arr[nr][nc], arr[r][c]);
                } else {
                    if (arr[r][c] == arr[nr][nc] && !combined[nr][nc]) {
                        combined[nr][nc] = true;
                        arr[nr][nc] *= 2;
                        arr[r][c] = 0;
                    } else {
                        nr -= dr[dir];
                        nc -= dc[dir];
                        swap(arr[nr][nc], arr[r][c]);
                    }
                }
            }
        }
    }

    if (cnt == 5) {
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = 0; j < arr.size(); ++j) {
                answer = max(answer, arr[i][j]);
            }
        }
    } else {
        for (int ndir = 0; ndir < 4; ++ndir) {
            f(arr, ndir, cnt + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int> > arr(N, vector<int> (N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
        }
    }

    for (int dir = 0; dir < 4; ++dir) {
        f(arr, dir, 1);
    }

    cout << answer << '\n';
}
