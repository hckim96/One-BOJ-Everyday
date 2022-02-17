#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> A(2 * N + 1, 0), B(M + 1, 0);
    vector<vector<int> > adj(2 * N + 1);

    for (int i = 1; i <= N; ++i) {
        int num;
        cin >> num;
        while (num--) {
            int m;
            cin >> m;
            adj[2 * i - 1].push_back(m);
            adj[2 * i].push_back(m);
        }
    }

    vector<int> visited(2 * N + 1, false);
    function<bool(int)> f = [&](int a) {
        visited[a] = true;
        for (auto b: adj[a]) {
            if (!B[b] || (!visited[B[b]] && f(B[b]))) {
                A[a] = b;
                B[b] = a;
                return true;
            }            
        }
        return false;
    };

    int match = 0;
    for (int i = 1; i <= 2 * N; i += 2) {
        if (!A[i]) {
            fill(all(visited), false);
            if (f(i)) ++match;
        }
    }
    int matched2 = 0;
    for (int i = 2; i <= 2 * N && matched2 < K; i += 2) {
        if (!A[i]) {
            fill(all(visited), false);
            if (f(i)) ++matched2;
        }
    }

    cout << match + matched2 << '\n';
}