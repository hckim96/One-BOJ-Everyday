#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1e6

bool bfs(vector<vector<int> >& adj, vector<vector<int> >& c, vector<vector<int> >& f, vector<int>& level, int S, int T) {
    fill(level.begin(), level.end(), -1);

    queue<int> q;
    q.push(S);
    level[S] = 0;

    while (!q.empty()) {
        auto qf = q.front();
        q.pop();

        for (auto e: adj[qf]) {
            if (level[e] == -1 && c[qf][e] - f[qf][e] > 0) {
                level[e] = level[qf] + 1;
                q.push(e);
            }
        }
    }
    
    return level[T] != -1;
}

int dfs(vector<vector<int> >& adj, vector<vector<int> >& c, vector<vector<int> >& f, vector<int>& level, vector<int>& todo , int cur, int dest, int flow) {
    if (cur == dest) {
        return flow;
    }

    for (int& i = todo[cur]; i < adj[cur].size(); ++i) {
        int next = adj[cur][i];

        if (level[next] == level[cur] + 1 && c[cur][next] - f[cur][next] > 0) {

            int bf = dfs(adj, c, f, level, todo, next, dest, min(flow, c[cur][next] - f[cur][next]));

            if (bf) {
                f[cur][next] += bf;
                f[next][cur] -= bf;
                return bf;
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int S = N;
    int T = N + 1;

    vector<vector<int> > adj(T + 1);
    vector<vector<int> > f(T + 1, vector<int> (T + 1, 0));
    vector<vector<int> > c(T + 1, vector<int> (T + 1, 0));

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        if (num == 1) {
            c[S][i] = INF;
            adj[S].push_back(i);
            adj[i].push_back(S);
        } else if (num == 2) {
            c[i][T] = INF;
            adj[i].push_back(T);
            adj[T].push_back(i);
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> c[i][j];

            if (i != j) {
                adj[i].push_back(j);
            }
        }
    }


    int minCut = 0;

    vector<int> level(T + 1, -1);
    while (bfs(adj, c, f, level, S, T)) {
        vector<int> todo(T + 1, 0);
        while (true) {
            int bf = dfs(adj, c, f, level, todo, S, T, INF);
            if (!bf) {
                break;
            }
            minCut += bf;
        }
    }

    cout << minCut << '\n';

    vector<bool> visited(T + 1, false);
    queue<int> q;
    q.push(S);
    visited[S] = true;

    while (!q.empty()) {
        auto qf = q.front();
        q.pop();

        for (auto e: adj[qf]) {
            if (!visited[e] && c[qf][e] - f[qf][e] > 0) {
                q.push(e);
                visited[e] = true;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        if (visited[i]) {
            cout << i + 1 << ' ';
        }
    }
    cout << '\n';

    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            cout << i + 1 << ' ';
        }
    }
    cout << '\n';
}