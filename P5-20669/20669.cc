#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

vector<vector<long long> > operator *(vector<vector<long long> > v1, vector<vector<long long> > v2) {
    vector<vector<long long> > ret(v1.size(), vector<long long> (v2[0].size(), 0));
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[0].size(); ++j) {
            for (int k = 0; k < v1[0].size(); ++k) {
                ret[i][j] += v1[i][k] * v2[k][j];
                ret[i][j] %= MOD;
            }
        }
    }
    return ret;
};

vector<vector<long long> > operator +(vector<vector<long long> > v1, vector<vector<long long> > v2) {
    vector<vector<long long> > ret(v1.size(), vector<long long> (v1[0].size(), 0));
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[0].size(); ++j) {
            ret[i][j] = v1[i][j] + v2[i][j];
            ret[i][j] %= MOD;
        }
    }
    return ret;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<long long> > arr(N + 2, vector<long long> (N + 2, 0));
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;

        ++arr[u][v];
        ++arr[v][u];
    }

    int psz, qsz;
    cin >> psz >> qsz;
    while (psz--) {
        int num;
        cin >> num;
        ++arr[0][num];
    }
    while (qsz--) {
        int num;
        cin >> num;
        ++arr[num][N + 1];
    }
    arr[N + 1][N + 1] = 1;

    auto arr2 = arr * arr;

    vector<vector<long long> > unit(N + 2, vector<long long> (N + 2, 0));
    for (int i = 0; i < unit.size(); ++i) {
        unit[i][i] = 1;
    }

    int power = K + 2;
    auto ret = unit;
    auto tmp = arr;
    
    while (power) {
        if (power & 1) ret = ret * tmp;
        tmp = tmp * tmp;
        power >>= 1;
    }

    cout << ret[0][N + 1] - arr2[0][N + 1] << '\n';
}