#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--) {
        int N;
        cin >> N;

        vector<vector<int> > adj(N + 1, vector<int> (N + 1, 0));
        vector<int> tmp;

        vector<int> indegree(N + 1, 0);
        for (int i = 0; i < N; ++i) {
            int num;
            cin >> num;

            for (auto e: tmp) {
                adj[e][num] = 1;
                ++indegree[num];
            }
            tmp.push_back(num);
        }

        int M;
        cin >> M;
        while (M--) {
            int a, b;
            cin >> a >> b;
            if (adj[a][b]) {
                --indegree[b];
                ++indegree[a];
            } else {
                --indegree[a];
                ++indegree[b];
            }
            swap(adj[a][b], adj[b][a]);
        }

        queue<int> q;
        int cnt = 0;
        for (int i = 1; i <= N; ++i) {
            if (indegree[i] == 0) {
                ++cnt;
                q.push(i);
            }
        }

        if (cnt > 1) {
            cout << "?\n";
            continue;
        }

        vector<int> answer;
        bool flag = false;
        while (!q.empty()) {
            auto f = q.front();
            answer.push_back(f);
            q.pop();
            if (!q.empty()) {
                flag = true;
                break;
            }

            for (int i = 1; i <= N; ++i) {
                if (adj[f][i]) {
                    --indegree[i];
                    if (indegree[i] == 0) {
                        q.push(i);
                    }
                }
            }
        }
        if (flag) {
            cout << "?\n";
            continue;
        }

        if (answer.size() != N) {
            cout << "IMPOSSIBLE\n";
        } else {
            for (auto e: answer) {
                cout << e << ' ';
            }
            cout << '\n';
        }
    }
}