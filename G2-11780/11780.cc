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

    vector<vector<long long> > adj(N + 1, vector<long long> (N + 1, 1e18));
    vector<vector<int> > prev(N + 1, vector<int> (N + 1, -1));
    for (int i = 1; i <= N; ++i) adj[i][i] = 0;
    while (M--) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (adj[a][b] > c) {
            adj[a][b] = c;
            prev[a][b] = a;
        }
    }

    for (int j = 1; j <= N; ++j) {
        for (int i = 1; i <= N; ++i) {
            for (int k = 1; k <= N; ++k) {
                if (adj[i][k] > adj[i][j] + adj[j][k]) {
                    adj[i][k] = adj[i][j] + adj[j][k];
                    prev[i][k] = prev[j][k];
                }
            }
        }
    }
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (adj[i][j] == 1e18) {
                cout << "0 ";
            } else {
                cout << adj[i][j] << ' ';
            }
        }
        cout << '\n';
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i == j || adj[i][j] == 1e18) {
                cout << "0\n";
                continue;
            }

            vector<int> tmp;
            int cur = j;
            while (cur != i) {
                tmp.push_back(cur);
                cur = prev[i][cur];
            }
            tmp.push_back(i);

            reverse(all(tmp));

            cout << tmp.size() << ' ';
            for (auto e: tmp) cout << e << ' ';
            cout << '\n';
        }
    }
}