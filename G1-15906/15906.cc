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
    
    int N, T, R, C;
    cin >> N >> T >> R >> C;
    --R;
    --C;

    vector<string> v(N);
    for (auto& e: v) cin >> e;

    vector<vector<vector<long long> > > dp(N, vector<vector<long long> > (N, vector<long long> (2, 1e18)));

    priority_queue<tuple<long long, int, int, int> > pq;

    dp[0][0][0] = 0;
    pq.push({-dp[0][0][0], 0, 0, 0});

    while (pq.size()) {
        auto [cc, fr, fc, fm] = pq.top();
        pq.pop();

        cc = -cc;
        if (cc > dp[fr][fc][fm]) continue;
        if (fr == R && fc == C) {
            cout << cc << '\n';
            return 0;
        }

        for (int dir = 0; dir < 4; ++dir) {
            int nr = fr + dr[dir];
            int nc = fc + dc[dir];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if (cc + 1 >= dp[nr][nc][0]) continue;

            dp[nr][nc][0] = cc + 1;
            pq.push({-dp[nr][nc][0], nr, nc, 0});
        }
        if (!fm) cc += T;
        for (int dir = 0; dir < 4; ++dir) {
            int nr = fr + dr[dir];
            int nc = fc + dc[dir];
            while (0 <= nr && nr < N && 0 <= nc && nc < N && v[nr][nc] != '#') {
                nr += dr[dir];
                nc += dc[dir];
            }
            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if (cc + 1 >= dp[nr][nc][1]) continue;

            dp[nr][nc][1] = cc + 1;
            pq.push({-dp[nr][nc][1], nr, nc, 1});
        }
    }
}