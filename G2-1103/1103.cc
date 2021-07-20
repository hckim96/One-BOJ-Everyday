#include <iostream>
#include <vector>

using namespace std;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

#define INF 987654321

bool flag = false;

int f(vector<vector<int> >& arr, vector<vector<int> >& dp, vector<vector<bool> >& visited, int i, int j) {
    if (i < 0 || i >= arr.size() || j < 0 || j >= arr[0].size() || arr[i][j] == 'H' - '0') {
        return 0;
    }

    if (visited[i][j]) {
        flag = true;
        return INF;
    }

    if (flag) {
        return INF;
    }

    int& ret = dp[i][j];

    if (ret != -1) {
        return ret;
    }

    visited[i][j] = true;
    int tmp = 0;
    for (int dir = 0; dir < 4; ++dir) {
        if (flag) {
            return ret = INF;
        }
        int ni = i + dr[dir] * arr[i][j];
        int nj = j + dc[dir] * arr[i][j];

        tmp = max(tmp, f(arr, dp, visited, ni, nj) + 1);
    }

    visited[i][j] = false;
    return ret = tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int> > dp(N, vector<int> (M, -1));
    vector<vector<int> > arr(N, vector<int> (M));
    vector<vector<bool> > visited(N, vector<bool> (M, false));

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < M; ++j) {
            arr[i][j] = s[j] - '0';
        }
    }

    f(arr, dp, visited, 0, 0);
    
    if (flag) {
        cout << "-1\n";
    } else {
        cout << dp[0][0] << '\n';
    }
}