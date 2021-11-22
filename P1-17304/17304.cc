#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, M;
    cin >> N >> M;


    set<pair<int, int> > s;
    vector<int> defended(N + 1);
    vector<vector<int> > adj(N + 1);

    while (M--) {
        int a, b;
        cin >> a >> b;
        auto it = s.find({b, a});
        if (it != s.end()) {
            --defended[a];
            adj[a].push_back(b);
            adj[b].push_back(a);
            s.erase(it);
        } else {
            ++defended[b];
            s.insert({a, b});
        }
    }

    vector<int> visited(N + 1, false);

    int left = 0;
    for (int i = 1; i <= N; ++i) {
        if (!defended[i]) ++left;
    }

    auto f = [&](int start) {
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        int defendedCnt = 0;
        bool isTree = true;
        int size = 0;

        while (q.size()) {
            ++size;
            auto f = q.front();
            q.pop();
            if (defended[f]) ++defendedCnt;

            for (auto e: adj[f]) {
                if (visited[e] && visited[e] == visited[f] - 1) continue; // parent
                if (visited[e]) {
                    isTree = false;
                    continue;
                }
                visited[e] = visited[f] + 1;
                q.push(e);
            }
        }


        if (defendedCnt || !isTree) {
            left -= size - defendedCnt;
        }
        return defendedCnt || !isTree;
    };

    for (int i = 1; i <= N; ++i) {
        if (adj[i].size() && !visited[i] && !f(i)) {
            cout << "NO\n";
            return 0;
        }
    }

    if (left) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}