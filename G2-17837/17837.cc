#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

#define INF 987654321

int dr[5] = {INF, 0, 0, -1, 1};
int dc[5] = {INF, 1, -1, 0, 0};
enum Color {
    WHITE,
    RED,
    BLUE
};

int reverseDir(int dir) {
    if (dir == 1) {
        return 2;
    } else if (dir == 2) {
        return 1;
    } else if (dir == 3) {
        return 4;
    } else {
        return 3;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<vector<int> > color(N + 1, vector<int> (N + 1));
    vector<tuple<int, int, int> > piece(K + 1);

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> color[i][j];
        }
    }

    vector<vector<vector<int> > > pieceNumAt(N + 1, vector<vector<int> > (N + 1));
    for (int i = 1; i <= K; ++i) {
        auto& [r, c, dir] = piece[i];
        cin >> r >> c >> dir;
        pieceNumAt[r][c].push_back(i); 
    }

    int turn = 0;
    while (++turn < 1000) {
        for (int i = 1; i <= K; ++i) {
            auto [r, c, dir] = piece[i];

            int nr = r + dr[dir];
            int nc = c + dc[dir];
            int ndir = dir;

            if (nr < 1 || nr >= color.size() || nc < 1 || nc >= color.size() || color[nr][nc] == BLUE) {
                ndir = reverseDir(dir);
                nr = r + dr[ndir];
                nc = c + dc[ndir];

                if (nr < 1 || nr >= color.size() || nc < 1 || nc >= color.size() || color[nr][nc] == BLUE) {
                    piece[i] = {r, c, ndir};
                    continue;
                }
                get<2>(piece[i]) = ndir;
            }

            auto it = find(pieceNumAt[r][c].begin(), pieceNumAt[r][c].end(), i);
            if (color[nr][nc] == RED) {
                reverse(it, pieceNumAt[r][c].end());
            }

            int cnt = pieceNumAt[r][c].end() - it;

            while (it != pieceNumAt[r][c].end()) {
                pieceNumAt[nr][nc].push_back(*it);
                piece[*it] = {nr, nc, get<2>(piece[*it])};
                ++it;
            }
            if (pieceNumAt[nr][nc].size() >= 4) {
                cout << turn << '\n';
                return 0;
            }

            while (cnt--) {
                pieceNumAt[r][c].pop_back();
            }
        }
    }
    cout << "-1\n";
}