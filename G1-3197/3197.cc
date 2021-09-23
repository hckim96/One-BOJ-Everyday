#include <iostream>
#include <queue>

using namespace std;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

queue<pair<int, int> > meltAdjacentIce(vector<string>& arr, vector<vector<bool> >& waterVisited, queue<pair<int, int> >& q) {
    queue<pair<int, int> > nextQ;
    while (!q.empty()) {
        auto [fr, fc] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nr = fr + dr[dir];
            int nc = fc + dc[dir];

            if (nr < 0 || nr >= arr.size() || nc < 0 || nc >= arr[0].size()) {
                continue;
            }

            if (waterVisited[nr][nc]) {
                continue;
            }

            if (arr[nr][nc] == 'X') {
                arr[nr][nc] = '.';
                nextQ.push({nr, nc});
                waterVisited[nr][nc] = true;
            } else {
                q.push({nr, nc});
                waterVisited[nr][nc] = true;
            }
        }
    }
    return nextQ;
}

queue<pair<int, int> > moveSwan(vector<string>& arr, vector<vector<bool> >& swanVisited, queue<pair<int, int> >& q) {

    queue<pair<int, int> > nextQ;

    while (!q.empty()) {
        auto [fr, fc] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nr = fr + dr[dir];
            int nc = fc + dc[dir];

            if (nr < 0 || nr >= arr.size() || nc < 0 || nc >= arr[0].size()) {
                continue;
            }

            if (swanVisited[nr][nc]) {
                continue;
            }

            if (arr[nr][nc] == 'X') {
                nextQ.push({nr, nc});
                swanVisited[nr][nc] = true;
            } else if (arr[nr][nc] == 'L') {
                swanVisited[nr][nc] = true;
                return nextQ;
            } else {
                q.push({nr, nc});
                swanVisited[nr][nc] = true;
            }
        }
    }
    return nextQ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    cin >> R >> C;

    vector<string> arr(R);
    pair<int, int> swan1 = {-1, -1};
    pair<int, int> swan2 = {-1, -1};
    vector<vector<bool> > waterVisited(R, vector<bool> (C, false));
    vector<vector<bool> > swanVisited(R, vector<bool> (C, false));
    queue<pair<int, int> > waterQ;
    queue<pair<int, int> > swanQ;

    for (int i = 0; i < R; ++i) {
        cin >> arr[i];
        for (int j = 0; j < C; ++j) {
            if (arr[i][j] == 'L') {
                if (swan1.first == -1) {
                    swan1 = {i, j};
                    swanQ.push({i, j});
                    swanVisited[i][j] = true;
                } else {
                    swan2 = {i, j};
                }
                waterQ.push({i, j});
                waterVisited[i][j] = true;
            } else if (arr[i][j] == '.') {
                waterQ.push({i, j});
                waterVisited[i][j] = true;
            }
        }
    }

    int day = 0;
    
    while (true) {
        swanQ = moveSwan(arr, swanVisited, swanQ);
        if (swanVisited[swan2.first][swan2.second]) {
            break;
        }
        waterQ = meltAdjacentIce(arr, waterVisited, waterQ);
        ++day;
    }
    cout << day << '\n';
}