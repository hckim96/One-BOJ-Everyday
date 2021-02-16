#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, N, K;

    cin >> T;
    
    while (T--) {
        cin >> N >> K;

        vector<int> D(N + 1);
        for (int i = 1; i <= N; ++i) {
            cin >> D[i];
        }

        vector<vector<int> > dep(N + 1, vector<int> ());
        vector<int> indegree(N + 1, 0);
        vector<int> time(N + 1, 0);

        for (int i = 0; i < K; ++i) {
            int X, Y;
            cin >> X >> Y;

            dep[X].push_back(Y);
            ++indegree[Y];
        }

        int W;
        cin >> W;

        queue<int> q;
        for (int i = 1; i <= N; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
                time[i] = D[i];
            }
        }

        while (!q.empty()) {
            int f = q.front();
            q.pop();

            if (f == W) {
                cout << time[f] << '\n';
                break;
            }

            for (auto e: dep[f]) {
                --indegree[e];
                time[e] = max(time[e], time[f] + D[e]);
                if (indegree[e] == 0) {
                    q.push(e);
                }               
            }
        }
    }
}