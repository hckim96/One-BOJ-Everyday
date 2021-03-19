#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
vector<vector<bool> > selected(5, vector<bool> (5, false));
vector<vector<char> > arr(5, vector<char> (5));
int answer = 0;

int check(int i, int j) {
    int ret = 1;
    queue<pair<int, int> > q;
    vector<vector<bool> > visited(5, vector<bool> (5, false));
    visited[i][j] = true;
    q.push({i, j});

    while (!q.empty()) {
        auto [fr, fc] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nr = fr + dr[dir];
            int nc = fc + dc[dir];

            if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) {
                continue;
            }
            if (!selected[nr][nc]) {
                continue;
            }
            if (visited[nr][nc]) {
                continue;
            }

            visited[nr][nc] = true;
            ++ret;
            q.push({nr, nc});
        }
        if (ret == 7) {
            break;
        }
    }
    return ret;
}

void f(int idx, int selectedNum, int yNum) {
    if (yNum >= 4) {
        return;
    }

    if (selectedNum == 7) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (selected[i][j]) {
                    if (check(i, j) == 7) {
                        ++answer;
                        return;
                    } else {
                        return;
                    }
                }
            }
        }
        return;
    }

    for (int nidx = idx; nidx < 25; ++nidx) {
        int nr = nidx / 5;
        int nc = nidx % 5;

        if(selected[nr][nc]) {
            continue;
        }

        selected[nr][nc] = true;
        f(nidx, selectedNum + 1, yNum + (arr[nr][nc] == 'Y'));
        selected[nr][nc] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 5; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < 5; ++j) {
            arr[i][j] = s[j];
        }
    }

    f(0, 0, 0);
    cout << answer << '\n';
}