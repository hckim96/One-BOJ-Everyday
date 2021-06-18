#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void f(vector<vector<int> >& adj, vector<bool>& visited, vector<int>& arr, vector<int>& group, int cur, int groupNum) {
    visited[cur] = true;

    for (auto e: adj[cur]) {
        if (!visited[e]) {
            f(adj, visited, arr, group, e, groupNum);
        }
    }

    if (groupNum) {
        group[cur] = groupNum;
    } else {
        arr.push_back(cur);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int> > adj(2 * N + 1);
    vector<bool> visited(2 * N + 1, false);
    vector<int> group(2 * N + 1, 0);
    vector<vector<int> > adj_rev(2 * N + 1);
    
    while (M--) {
        int n1, n2;
        cin >> n1 >> n2;

        adj[N - n1].push_back(N + n2);
        adj[N - n2].push_back(N + n1);
        adj_rev[N + n2].push_back(N - n1);
        adj_rev[N + n1].push_back(N - n2);
    }

    vector<int> arr;

    for (int i = 0; i <= 2 * N; ++i) {
        if (i == N) {
            continue;
        }

        if (!visited[i]) {
            f(adj, visited, arr, group, i, 0);
        }
    }

    fill(visited.begin(), visited.end(), false);

    int cnt = 1;
    for (auto it = arr.rbegin(); it != arr.rend(); ++it) {
        if (!visited[*it]) {
            f(adj_rev, visited, arr, group, *it, cnt++);
        }
    }

    bool canBeTrue = true;
    for (int i = 1; i <= N; ++i) {
        if (group[N + i] == group[N - i]) {
            canBeTrue = false;
            break;
        }
    }

    cout << canBeTrue << '\n';

    if (!canBeTrue) {
        return 0;
    }

    vector<int> answer(N + 1, -1);

    vector<pair<int, int> > tmp;

    for (int i = 1; i <= N; ++i) {
        tmp.push_back({group[N + i], i});
        tmp.push_back({group[N - i], -i});
    }

    sort(tmp.begin(), tmp.end());

    for (auto [g, n]: tmp) {
        if (answer[abs(n)] != -1) {
            continue;
        }
        
        if (n > 0) {
            answer[n] = 0;
        } else {
            answer[-n] = 1;
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << answer[i] << ' ';
    }
    cout << '\n';
}
