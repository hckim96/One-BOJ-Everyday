#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(vector<vector<int> >& adj, vector<int>& discoveredTime, vector<pair<int, int> >& bridge, int& time, int parent, int cur) {
    discoveredTime[cur] = ++time;

    int ret = discoveredTime[cur];
    for (auto e: adj[cur]) {
        if (e == parent) {
            continue;
        }

        if (discoveredTime[e]) {
            ret = min(ret, discoveredTime[e]);
            continue;
        }

        int tmp = f(adj, discoveredTime, bridge, time, cur, e);
        ret = min(ret, tmp);

        if (tmp > discoveredTime[cur]) {
            if (cur < e) {
                bridge.push_back({cur, e});
            } else {
                bridge.push_back({e, cur});
            }
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;

    vector<vector<int> > adj(V + 1);
    vector<int> discoveredTime(V + 1, 0);
    vector<pair<int, int> > bridge;
    int time = 0;

    for (int i = 0; i < E; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    for (int i = 1; i <= V; ++i) {
        if (!discoveredTime[i]) {
            f(adj, discoveredTime, bridge, time, 0, i);
        }
    }

    sort(bridge.begin(), bridge.end());

    cout << bridge.size() << '\n';
    for (auto [v1, v2]: bridge) {
        cout << v1 << ' ' << v2 << '\n';
    }
}
