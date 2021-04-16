#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int answer = INF;

bool moveRed(vector<vector<char> >& arr, pair<int, int>& red, pair<int, int>& blue, int dir) {
    auto [r, c] = red;

    if (arr[r][c] == 'O') {
        return true;
    }

    int i = 1;
    while (true) {
        int nr = r + dr[dir] * i;
        int nc = c + dc[dir] * i;

        if (nr < 0 || nr >= arr.size() || nc < 0 || nc >= arr[0].size()) {
            --i;
            break;
        }

        if (arr[nr][nc] == '#') {
            --i;
            break;
        }

        if (arr[nr][nc] == 'O') {
            red = {nr, nc};
            return true;
        }

        if (blue.first == nr && blue.second == nc) {
            --i;
            break;
        }


        ++i;
    }

    red = {r + dr[dir] * i, c + dc[dir] * i};
    return false;
}
bool moveBlue(vector<vector<char> >& arr, pair<int, int>& red, pair<int, int>& blue, int dir) {
    auto [r, c] = blue;

    if (arr[r][c] == 'O') {
        return true;
    }

    int i = 1;
    while (true) {
        int nr = r + dr[dir] * i;
        int nc = c + dc[dir] * i;

        if (nr < 0 || nr >= arr.size() || nc < 0 || nc >= arr[0].size()) {
            --i;
            break;
        }
        
        if (arr[nr][nc] == '#') {
            --i;
            break;
        }

        if (arr[nr][nc] == 'O') {
            blue = {nr, nc};
            return true;
        }

        if (red.first == nr && red.second == nc) {
            --i;
            break;
        }


        ++i;
    }

    blue = {r + dr[dir] * i, c + dc[dir] * i};
    return false;
}

void f(vector<vector<char> >& arr, pair<int, int> red, pair<int, int> blue, int dir, int cnt) {

    bool r = moveRed(arr, red, blue, dir);
    bool b = moveBlue(arr, red, blue, dir);
    r = moveRed(arr, red, blue, dir);

    if (b) {
        return;
    }

    if (r) {
        answer = min(answer, cnt);
        return;
    }

    if (cnt == 10) {
        return;
    }
    if (answer <= cnt + 1) {
        return;
    }

    for (int nd = 0; nd < 4; ++nd) {
        if (nd == dir) {
            continue;
        }

        f(arr, red, blue, nd, cnt + 1);
    }

    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<char> > arr(N, vector<char> (M));

    pair<int, int> red;
    pair<int, int> blue;

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < M; ++j) {
            arr[i][j] = s[j];
            if (arr[i][j] == 'R') {
                red = {i, j};
            }
            if (arr[i][j] == 'B') {
                blue = {i, j};
            }
        }
    }

    for (int d = 0; d < 4; ++d) {
        f(arr, red, blue, d, 1);
    }

    if (answer == INF) {
        cout << "-1\n";
    } else {
        cout << answer << '\n';
    }
}
