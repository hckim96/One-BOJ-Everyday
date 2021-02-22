#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int maxDistV = 0;
int maxDist = 0;

void dfs(vector<vector<pair<int, int> > >& edge, vector<bool>& visited, int curV, int curDist) {

    if (maxDist < curDist) {
        maxDist = curDist;
        maxDistV = curV;
    }

    for (auto e: edge[curV]) {
        if (!visited[e.first]) {
            visited[e.first] = true;
            dfs(edge, visited, e.first, curDist + e.second);
            visited[e.first] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V;
    cin >> V;
    
    vector<vector<pair<int, int> > > edge(V + 1, vector<pair<int, int> > ());

    int v1, v2, w;

    for (int i = 0; i < V; ++i) {
        cin >> v1;
        while (true) {
            cin >> v2;
            if (v2 == -1) {
                break;
            }
            cin >> w;

            edge[v1].push_back({v2, w});
        }
    }

    vector<bool> visited(V + 1, false);
    visited[1] = true;
    dfs(edge, visited, 1, 0);

    fill(visited.begin(), visited.end(), false);
    visited[maxDistV] = true;
    dfs(edge, visited, maxDistV, 0);   
    
    cout << maxDist << '\n';
}