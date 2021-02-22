#include <iostream>
#include <vector>

using namespace std;


int f(vector<vector<int> >& dp, vector<pair<int, int> >& matrix, int s, int e) {
    if (s == e) {
        return 0;
    }

    if (dp[s][e] != -1) {
        return dp[s][e];
    }

    int ret = INT32_MAX;

    for (int i = s; i < e; ++i) {
        ret = min(ret, f(dp, matrix, s, i) + f(dp, matrix, i + 1, e) + matrix[s].first * matrix[i].second * matrix[e].second);
    }

    return dp[s][e] = ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int> > matrix(N, {0, 0});

    for (auto & e: matrix) {
        cin >> e.first >> e.second;
    }

    vector<vector<int> > dp(N, vector<int> (N, -1));
    
    cout << f(dp, matrix, 0, N - 1) << '\n';

}