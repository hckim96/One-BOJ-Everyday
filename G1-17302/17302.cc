#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);


    int N, M;
    cin >> N >> M;
    vector<vector<int> > v(N, vector<int> (M, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char c;
            cin >> c;
            if (c == 'W') {
                v[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int dir = 0; dir < 4; ++dir) {
                int nr = i + dr[dir];
                int nc = j + dc[dir];
                if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
                v[nr][nc] = v[nr][nc] ^ 1;
            }
        }
    }

    cout << "1\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (v[i][j]) {
                cout << '2';
            } else {
                cout << '3';
            }
        }
        cout << '\n';
    }
}
