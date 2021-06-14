#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int counter = 0;

int f(vector<vector<int> >& adj, vector<int>& discoveredTime, vector<bool>& isAP, int cur, bool isRoot) {
    discoveredTime[cur] = ++counter;
    int child = 0;
    int minReachableTime = discoveredTime[cur];

    for (auto e: adj[cur]) {
        if (discoveredTime[e]) {
            minReachableTime = min(minReachableTime, discoveredTime[e]);
            continue;
        }

        ++child;

        int tmp = f(adj, discoveredTime, isAP, e, false);

        if (!isRoot && tmp >= discoveredTime[cur]) {
            isAP[cur] = true;
        }
        minReachableTime = min(minReachableTime, tmp);
    }

    if (isRoot && child >= 2) {
        isAP[cur] = true;
    }

    return minReachableTime;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;

    vector<int> discoveredTime(V + 1, 0);
    vector<vector<int> > adj(V + 1);
    vector<bool> isAP(V + 1, false);


    for (int i = 0; i < E; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    for (int i = 1; i <= V; ++i) {
        if (!discoveredTime[i]) {
            f(adj, discoveredTime, isAP, i, true);
        }
    }

    vector<int> answer;

    for (int i = 1; i <= V; ++i) {
        if (isAP[i]) {
            answer.push_back(i);
        }
    }

    cout << answer.size() << '\n';

    for (auto e: answer) {
        cout << e << ' ';
    }
    cout << '\n';
}
