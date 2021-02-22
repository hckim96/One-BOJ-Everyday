#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 987654321

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    vector<int> time(N + 1, 0);
    vector<vector<int> > dep(N + 1, vector<int> ());
    vector<int> inDegree(N + 1, 0);
    vector<int> dp(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        cin >> time[i + 1];
        while (true) {
            int tmp;
            cin >> tmp;
            if (tmp == -1) {
                break;
            }
            dep[tmp].push_back(i + 1);
            ++inDegree[i + 1];
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (inDegree[i] == 0) {
            dp[i] = time[i];
            q.push(i);
        }
    }

    while (!q.empty()) {
        int f = q.front();
        q.pop();

        for (auto e: dep[f]) {
            dp[e] = max(dp[e], dp[f] + time[e]);
            --inDegree[e];
            if (inDegree[e] == 0) {
                q.push(e);
            }
        }
    }
    
    for (int i = 1; i <= N; ++i) {
        cout << dp[i] << '\n';
    }

}