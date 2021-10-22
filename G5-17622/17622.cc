#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<vector<int> > arr;

int N, K;
const int INF = 1e9;

vector<vector<int> > nextDir = {
    {1, -1, -1, 2},
    {3, 2, -1, -1},
    {-1, -1, 1, 0},
    {-1, 0, 3, -1},
    {0, -1, 2, -1},
    {-1, 1, -1, 3},
};

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int getDistance() {
    tuple<int, int, int> cur = {0, -1, 1};

    int ret = 0;
    while (true) {
        auto [r, c, d] = cur;
        if (r == N - 1 && c == N - 1 && d == 1) {
            return ret;
        }
        int nr = r + dr[d];
        int nc = c + dc[d];

        if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
            return INF;
        }

        int nd = nextDir[arr[nr][nc]][d];

        if (nd == -1) {
            return INF;
        }

        cur = {nr, nc, nd};
        ++ret;
    }

    return INF;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    cin >> N >> K;

    arr.resize(N, vector<int> (N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
        }
    }

    int answer = INF;
    if (K == 1) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int original = arr[i][j];
                for (int k = 0; k < 6; ++k) {
                    if (k == original) continue;
                    arr[i][j] = k;
                    answer = min(answer, getDistance());
                }
                arr[i][j] = original;
            }
        }
    } else {
        answer = getDistance();
    }

    if (answer == INF) {
        cout << "-1\n";
    } else {
        cout << answer << '\n';
    }
}