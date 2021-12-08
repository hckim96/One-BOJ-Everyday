#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int TC; cin >> TC;
    while (TC--) {
        int l;
        cin >> l;
        pair<int, int> s, e;
        cin >> s.first >> s.second;
        cin >> e.first >> e.second;

        vector<vector<int> > visited(l, vector<int> (l, false));
        queue<pair<int, int> > q;

        q.push(s);
        visited[s.first][s.second] = 1;

        while (q.size()) {
            auto [fr, fc] = q.front();
            q.pop();
            if (fr == e.first && fc == e.second) {
                cout << visited[fr][fc] - 1 << '\n';
                break;
            }
            for (int dir = 0; dir < 8; ++dir) {
                int nr = fr + dr[dir];
                int nc = fc + dc[dir];
                if (nr < 0 || nr >= l || nc < 0 || nc >= l) continue;
                if (visited[nr][nc]) continue;

                q.push({nr, nc});
                visited[nr][nc] = visited[fr][fc] + 1;
            }
        }
    }
}