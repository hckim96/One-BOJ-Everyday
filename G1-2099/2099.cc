#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

vector<vector<int> > operator*(vector<vector<int> > v1, vector<vector<int> > v2) {
    vector<vector<int> > ret(v1.size(), vector<int> (v2.size(), 0));
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[0].size(); ++j) {
            for (int k = 0; k < v1[0].size(); ++k) {
                ret[i][j] |= v1[i][k] & v2[k][j];
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, K, M;
    cin >> N >> K >> M;

    vector<vector<int> > adj(N + 1, vector<int> (N + 1, 0));

    for (int i = 1; i <= N; ++i) {
        int a, b;
        cin >> a >> b;
        adj[i][a] = adj[i][b] = 1;
    }

    vector<vector<int> > answer(N + 1, vector<int> (N + 1, 0));
    for (int i = 0; i < answer.size(); ++i) answer[i][i] = 1;

    while (K) {
        if (K & 1) {
            answer = answer * adj;
        }
        adj = adj * adj;
        K >>= 1;
    }

    while (M--) {
        int a, b;
        cin >> a >> b;

        if (answer[a][b]) {
            cout << "death\n";
        } else {
            cout << "life\n";
        }
    }
    
}