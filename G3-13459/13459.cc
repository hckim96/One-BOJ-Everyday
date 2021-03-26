#include <iostream>
#include <vector>

using namespace std;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int answer = -1;

bool moveBlue(vector<vector<char> >& map, pair<int, int>& red, pair<int, int>& blue, pair<int, int>& hole, int dir) {
    if (blue == hole) {
        return true;
    }

    int nr, nc;
    int d = 1;
    bool ret = false;
    
    while (true) {

        nr = blue.first + dr[dir] * d;
        nc = blue.second + dc[dir] * d;

        if (nr < 0 || nr >= map.size() || nc < 0 || nc >= map[0].size()) {
            break;
        }

        if (nr == hole.first && nc == hole.second) {
            blue = {nr, nc};
            return true;    
        }

        if (map[nr][nc] == '#') {
            break;
        }

        if (nr == red.first && nc == red.second) {
            break;
        }


        ++d;
    }

    nr -= dr[dir];
    nc -= dc[dir];

    blue = {nr, nc};

    return ret;
}

bool moveRed(vector<vector<char> >& map, pair<int, int>& red, pair<int, int>& blue, pair<int, int>& hole, int dir) {

    if (red == hole) {
        return true;
    }

    int nr, nc;
    int d = 1;
    bool ret = false;

    while (true) {
        nr = red.first + dr[dir] * d;
        nc = red.second + dc[dir] * d;

        if (nr < 0 || nr >= map.size() || nc < 0 || nc >= map[0].size()) {
            break;
        }

        if (nr == hole.first && nc == hole.second) {
            red = {nr, nc};
            return true;
        }

        if (map[nr][nc] == '#') {
            break;
        }

        if (nr == blue.first && nc == blue.second) {
            break;
        }


        ++d;
    }

    nr -= dr[dir];
    nc -= dc[dir];

    red = {nr, nc};

    return ret;
}

void tilt(vector<vector<char> >& map, pair<int, int>& red, pair<int, int>& blue, pair<int, int>& hole, int dir) {
    bool r = moveRed(map, red, blue, hole, dir);
    bool b = moveBlue(map, red, blue, hole, dir);
    if (!r) {
        r = r | moveRed(map, red, blue, hole, dir);
    }

    if (r && !b) {
        answer = 1;
        return;
    } else if (b) {
        return;
    }
}

void f(vector<vector<char> >& map, pair<int, int>& red, pair<int, int>& blue, pair<int, int>& hole, int cnt) {

    if (cnt == 10) {
        return;
    }

    if (answer != -1) {
        return;
    }

    if (red == hole && blue == hole) {
        return;
    }

    for (int dir = 0; dir < 4; ++dir) {
        if (answer != -1) {
            return;
        }
        auto [rr, rc] = red;
        auto [br, bc] = blue;
        rr += dr[dir];
        br += dr[dir];
        rc += dc[dir];
        bc += dc[dir];

        if ((map[rr][rc] == '#' ||  (rr == blue.first && rc == blue.second)) && (map[br][bc] == '#' ||  (br == red.first && bc == red.second))) {
            continue;
        }

        pair<int, int> red2(red);
        pair<int, int> blue2(blue);

        tilt(map, red2, blue2, hole, dir);
        f(map, red2, blue2, hole, cnt + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;
    
    vector<vector<char> > map(N, vector<char> (M));

    pair<int, int> red;
    pair<int, int> blue;
    pair<int, int> hole;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < M; ++j) {
            map[i][j] = s[j];
            if (map[i][j] == 'R') {
                red = {i, j};
            } else if (map[i][j] == 'B') {
                blue = {i, j};
            } else if (map[i][j] == 'O') {
                hole = {i, j};
            }
        }
    }

    f(map, red, blue, hole, 0);

    if (answer == 1) {
        cout << "1\n";
    } else {
        cout << "0\n";
    }
}