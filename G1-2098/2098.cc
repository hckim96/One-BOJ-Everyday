#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

int N;
int answer = INF;

int f(vector<vector<int> >& W, vector<vector<int> >& dp, int cur, int stat) {
    int& ret = dp[cur][stat];
    
    if (stat == (1 << N) - 1) {
        return W[cur][0] ? W[cur][0] : INF;
    }

    if (ret != -1) {
        return ret;
    }

    int tmp = INF;
    for (int next = 0; next < N; ++next) {
        if (W[cur][next] == 0) {
            continue;
        }

        if (stat & (1 << next)) {
            continue;
        }

        tmp = min(tmp, W[cur][next] + f(W, dp, next, stat | (1 << next)));
    }

    return ret = tmp;
}

int main() {

    cin >> N;

    vector<vector<int> > W(N, vector<int> (N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> W[i][j];
        }
    }

    vector<vector<int> > dp(N, vector<int> (1 << N, -1));

    cout << f(W, dp, 0, 1) << '\n';
}