#include <iostream>
#include <vector>

using namespace std;

vector<int> A;
vector<vector<int> > adj;

int seq = 1;
void f(int cur) {
    if (adj[cur].size() >= 1) f(adj[cur][0]);
    A[cur] = seq++;
    if (adj[cur].size() >= 2) f(adj[cur][1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;
    A.resize(N + 1);
    adj.resize(N + 1);
    vector<vector<int> > depth(N);

    depth[0] = {1};

    for (int i = 2; i <= N; ++i) {
        int d;
        cin >> d;
        depth[d].push_back(i);
        if (depth[d].size() > depth[d - 1].size() * 2) {
            cout << "-1\n";
            return 0;
        }
    }

    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < depth[i].size(); ++j) {
            int c1 = j << 1;
            int c2 = j << 1 | 1;
            if (c1 < depth[i + 1].size()) adj[depth[i][j]].push_back(depth[i + 1][c1]);
            if (c2 < depth[i + 1].size()) adj[depth[i][j]].push_back(depth[i + 1][c2]);
        }
    }

    f(1);

    for (int i = 1; i <= N; ++i) {
        cout << A[i] << ' ';
    }
    cout << '\n';
}