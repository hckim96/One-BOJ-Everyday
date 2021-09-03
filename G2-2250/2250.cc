#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

int order = 1;

void f(vector<vector<int> >& adj, vector<pair<int, int> >& pos, int cur, int level) {
    if (adj[cur][0] != -1) {
        f(adj, pos, adj[cur][0], level + 1);
    }

    ++order;    
    pos[level].first = min(pos[level].first, order);
    pos[level].second = max(pos[level].second, order);

    if (adj[cur][1] != -1) {
        f(adj, pos, adj[cur][1], level + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int> > adj(N + 1, vector<int> (2));
    vector<int> parent(N + 1, -1);

    for (int i = 1; i <= N; ++i) {
        int n, l, r;
        cin >> n >> l >> r;
        adj[n][0] = l;
        adj[n][1] = r;

        if (l != -1) {
            parent[l] = n;
        }
        if (r != -1) {
            parent[r] = n;
        }
    }

    int rootNum;

    for (int i = 1; i <= N; ++i) {
        if (parent[i] == -1) {
            rootNum = i;
            break;
        }
    }

    vector<pair<int, int> > pos(10001, {INF, -INF});

    f(adj, pos, rootNum, 1);

    pair<int, int> answer = {0, 0};

    for (int i = 1; i <= 10000; ++i) {
        if (pos[i].first == INF && pos[i].second == -INF) {
            break;
        }

        int width = pos[i].second - pos[i].first + 1;

        if (answer.second < width) {
            answer = {i, width};
        }
    }

    cout << answer.first << ' ' << answer.second << '\n';
}