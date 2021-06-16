#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000003

vector<vector<int> > operator*(vector<vector<int> >& m1, vector<vector<int> >& m2) {
    vector<vector<int> > ret(m1.size(), vector<int>(m2[0].size(), 0));

    for (int i = 0; i < m1.size(); ++i) {
        for (int j = 0; j < m2[0].size(); ++j) {
            for (int k = 0; k < m1[0].size(); ++k) {
                ret[i][j] = (1LL * m1[i][k] * m2[k][j] + ret[i][j]) % MOD;
            }
        }
    }
    return ret;
}

vector<vector<int> > f(vector<vector<int> > adj, int cnt) {
    vector<vector<int> > ret(adj.size(), vector<int> (adj.size(), 0));

    for (int i = 0; i < ret.size(); ++i) {
        ret[i][i] = 1;
    }

    while (cnt) {
        if (cnt & 1) {
            ret = ret * adj;
        }
        adj = adj * adj;
        cnt >>= 1;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, S, E, T;
    cin >> N >> S >> E >> T;
    
    vector<vector<int> > adj(5 * N, vector<int> (5 * N, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 4; ++j) {
            adj[5 * i + j + 1][5 * i + j] = 1;
        }
    }

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < N; ++j) {
            int t = s[j] - '0';
            if (t) {
                adj[5 * i][5 * j + t - 1] = 1;
            }
        }
    }

    auto answer = f(adj, T);

    cout << answer[5 * (S - 1)][5 * (E - 1)] << '\n';
}
