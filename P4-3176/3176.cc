#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

#define INF 2e6

pair<int, int> getAnswer(vector<vector<int> >& parent, vector<int>& depth, vector<vector<int> >& min_, vector<vector<int> >& max_, int n1, int n2) {
    if (depth[n2] > depth[n1]) {
        swap(n1, n2);
    }

    int diff = depth[n1] - depth[n2];

    int retMin = INF;
    int retMax = 0;

    int k = 0;
    while (diff) {
        if (diff & 1) {
            retMin = min(retMin, min_[n1][k]);
            retMax = max(retMax, max_[n1][k]);
            n1 = parent[n1][k];
        }
        ++k;
        diff >>= 1;
    }

    if (n1 == n2) {
        return {retMin, retMax};
    }

    for (int kk = parent[0].size() - 1; kk >= 0; --kk) {
        if (parent[n1][kk] && parent[n1][kk] != parent[n2][kk]) {
            retMin = min(retMin, min(min_[n1][kk], min_[n2][kk]));
            retMax = max(retMax, max(max_[n1][kk], max_[n2][kk]));
            n1 = parent[n1][kk];
            n2 = parent[n2][kk];
        }
    }

    return {min(retMin, min(min_[n1][0], min_[n2][0])), max(retMax, max(max_[n1][0], max_[n2][0]))};
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;

    cin >> N;
    vector<vector<pair<int, int> > > adj(N + 1);
    vector<vector<int> > parent(N + 1, vector<int> (ceil(log2(N - 1)) + 1, 0));
    vector<vector<int> > min_(N + 1, vector<int> (ceil(log2(N - 1)) + 1, INF));
    vector<vector<int> > max_(N + 1, vector<int> (ceil(log2(N - 1)) + 1, 0));
    vector<int> depth(N + 1, 0);

    for (int i = 0; i < N - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    queue<int> q;
    q.push(1);
    
    while (!q.empty()) {
        auto f = q.front();
        q.pop();

        for (auto [n, w]: adj[f]) {
            if (parent[n][0] || n == 1) {
                continue;
            }

            depth[n] = depth[f] + 1;
            int k = 0;
            parent[n][k] = f;
            min_[n][k] = max_[n][k] = w;
            ++k;
            while (parent[parent[n][k - 1]][k - 1]) {
                parent[n][k] = parent[parent[n][k - 1]][k - 1];
                min_[n][k] = min(min_[n][k - 1], min_[parent[n][k - 1]][k - 1]);
                max_[n][k] = max(max_[n][k - 1], max_[parent[n][k - 1]][k - 1]);
                ++k;
            }

            q.push(n);
        }
    }

    cin >> K;
    while (K--) {
        int d, e;
        cin >> d >> e;

        auto answer = getAnswer(parent, depth, min_, max_, d, e);

        cout << answer.first << ' ' << answer.second << '\n';
    }
}
