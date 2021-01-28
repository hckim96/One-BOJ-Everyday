#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

#define INF 987654321

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int N, M, G;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> G;

    int arr[N + 1][N + 1];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }


    int sr, sc;
    cin >> sr >> sc;
    vector<tuple<int, int, int, int> > passenger(M, tuple<int, int, int, int> ());

    for (int i = 0; i < M; i++) {
        int r, c, tr, tc;
        cin >> r >> c >> tr >> tc;

        passenger[i] = {r, c, tr, tc};
    }

    while (!passenger.empty()) {

        queue<pair<int, int> > q;
        vector<vector<int> > visited(N + 1, vector<int> (N + 1, -1));
        
        q.push({sr, sc});
        visited[sr][sc] = 0;
        while (!q.empty()) {
            auto [fr, fc] = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nr = fr + dr[dir];
                int nc = fc + dc[dir];

                if (nr < 1 || nr > N || nc < 1 || nc > N) {
                    continue;
                }
                if (arr[nr][nc] == 1) {
                    continue;
                }

                if (visited[nr][nc] != -1 && visited[nr][nc] <= visited[fr][fc] + 1) {
                    continue;
                }

                visited[nr][nc] = visited[fr][fc] + 1;
                q.push({nr, nc});
            }
        }

        int pr = INF;
        int pc = INF;
        int ptr = INF;
        int ptc = INF;
        vector<tuple<int, int, int, int> >::iterator pit;
        int pdistance = INF;
        for (auto it = passenger.begin(); it != passenger.end(); it++) {
            auto [r, c, tr, tc] = *it;
            if (visited[r][c] != -1) {
                if (pdistance > visited[r][c]) {
                    pdistance = visited[r][c];
                    pr = r;
                    pc = c;
                    ptr = tr;
                    ptc = tc;
                    pit = it;
                } else if (pdistance == visited[r][c]) {
                    if (r < pr) {
                        pr = r;
                        pc = c;
                        ptr = tr;
                        ptc = tc;
                        pit = it;
                    } else if (r == pr) {
                        if (c < pc) {
                            pr = r;
                            pc = c;
                            ptr = tr;
                            ptc = tc;
                            pit = it;
                        }
                    }
                }
            }
        }
        
        if (pdistance == INF) {
            cout << "-1\n";
            return 0;
        }

        passenger.erase(pit);

        G -= pdistance;
        if (G < 0) {
            cout << "-1\n";
            return 0;
        }
        for (auto & e: visited) {
            fill(e.begin(), e.end(), -1);
        }

        q.push({pr, pc});
        visited[pr][pc] = 0;

        while (!q.empty()) {
            auto [fr, fc] = q.front();
            q.pop();

            if (fr == ptr && fc == ptc) {
                break;
            }

            for (int dir = 0; dir < 4; dir++) {
                int nr = fr + dr[dir];
                int nc = fc + dc[dir];

                if (nr < 1 || nr > N || nc < 1 || nc > N) {
                    continue;
                }
                if (arr[nr][nc] == 1) {
                    continue;
                }

                if (visited[nr][nc] != -1 && visited[nr][nc] <= visited[fr][fc] + 1) {
                    continue;
                }

                visited[nr][nc] = visited[fr][fc] + 1;
                q.push({nr, nc});
            }
        }
        if (visited[ptr][ptc] == -1) {
            cout << "-1\n";
            return 0;
        }
        G -= visited[ptr][ptc];

        if (G < 0) {
            cout << "-1\n";
            return 0;
        }

        G += visited[ptr][ptc] * 2;

        sr = ptr;
        sc = ptc;
    }
    cout << G << "\n";
}