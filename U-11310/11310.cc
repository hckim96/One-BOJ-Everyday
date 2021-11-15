#include <bits/stdc++.h>

using namespace std;

int dr[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dc[8] = {1, -1, 0, 0, 1, -1, 1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<string> arr(N);
    for (auto &e: arr) cin >> e;

    vector<vector<int> > visited(N, vector<int> (M, 0));
    queue<pair<int, int> > q;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (arr[i][j] == 'W') {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    function<void(int, int)> f = [&](int fr, int fc) {
        for (int dir = 0; dir < 8; ++dir) {
            int nr = fr + dr[dir];
            int nc = fc + dc[dir];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if (visited[nr][nc]) continue;
            if (arr[nr][nc] == arr[fr][fc]) {
                q.push({nr, nc});
                visited[nr][nc] = true;
                f(nr, nc);
            }
        }
    };

    vector<int> answer(26, 1e9);
    int next = -1;
    while (q.size()) {
        int cnt = q.size();

        while (cnt--) {
            auto [fr, fc] = q.front();
            q.pop();
            f(fr,fc);
            q.push({fr, fc});
        }
        
        cnt = q.size();
        while (cnt--) {
            auto [fr, fc] = q.front();
            q.pop();
            answer[arr[fr][fc] - 'A'] = min(answer[arr[fr][fc] - 'A'], next);
            for (int dir = 0; dir < 8; ++dir) {
                int nr = fr + dr[dir];
                int nc = fc + dc[dir];

                if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
                if (visited[nr][nc]) continue;
                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
        ++next;
    }

    for (int i = 0; i < answer.size(); ++i) {
        if (answer[i] == 1e9 || i == 'W' - 'A') continue;
        cout << char(i + 'A') << ' ' << answer[i] << '\n'; 
    }
}