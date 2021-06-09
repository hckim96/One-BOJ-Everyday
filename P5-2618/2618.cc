#include <iostream>
#include <vector>

using namespace std;

int dist(pair<int,int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int f(vector<pair<int, int> >& arr, vector<vector<int> >& dp, int w1, int w2) {
    if (w1 == dp.size() -1 || w2 == dp.size() - 1) {
        return 0;
    }

    if (dp[w1][w2] != -1) {
        return dp[w1][w2];
    }

    int next = max(w1, w2) + 1;

    return dp[w1][w2] = min(f(arr, dp, next, w2) + dist(arr[next], arr[w1]), f(arr, dp, w1, next) + dist(arr[next], arr[w2]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, W;
    cin >> N >> W;

    vector<pair<int, int> > arr(W + 2);

    arr[0] = {1, 1};
    arr[1] = {N, N};

    for (int i = 2; i < W + 2; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }

    vector<vector<int> > dp(W + 2, vector<int> (W + 2, -1));

    cout << f(arr, dp, 0, 1) <<'\n';

    int w1, w2;
    w1 = 0;
    w2 = 1;

    while (w1 != W + 1 && w2 != W + 1) {
        int w3 = max(w1, w2) + 1;
        if (dp[w3][w2] + dist(arr[w1], arr[w3]) > dp[w1][w3] + dist(arr[w2], arr[w3])) {
            cout << "2\n";
            w2 = w3;
        } else {
            cout << "1\n";
            w1 = w3;
        }
    }
}
