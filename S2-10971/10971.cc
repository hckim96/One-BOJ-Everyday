#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<vector<int> > w(N, vector<int> (N, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> w[i][j];
        }
    }

    int answer = 1e9;
    vector<int> visited(N, false);
    function<void(int, int, int, int)> f = [&](int cur, int start, int cnt, int cost) {
        if (cost && cur == start) {
            if (cnt == N) {
                answer = min(answer, cost);
            }
            return;
        }

        for (int i = 0; i < N; ++i) {
            if (w[cur][i] == 0) continue;
            if (visited[i]) continue;

            visited[i] = true;
            f(i, start, cnt + 1, cost + w[cur][i]);
            visited[i] = false;
        }
    };

    f(0, 0, 0, 0);
    cout << answer << '\n';
}