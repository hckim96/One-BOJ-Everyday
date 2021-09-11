#include <iostream>
#include <vector>

using namespace std;
void f(vector<int>& arr, vector<vector<int> >& dp, int idx, int w) {
    if (idx == arr.size()) {
        return;
    }

    int& ret = dp[idx][w];

    if (ret) {
        return;
    }

    ret = true;

    f(arr, dp, idx + 1, w + arr[idx + 1]);
    f(arr, dp, idx + 1, abs(w - arr[idx + 1]));
    f(arr, dp, idx + 1, w);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(N, 0);
    for (auto& e: arr) {
        cin >> e;
    }

    vector<vector<int> > dp(N, vector<int> (500 * 30 + 1, 0));
    f(arr, dp, 0, 0);
    f(arr, dp, 0, arr[0]);

    int M;
    cin >> M;

    while (M--) {
        int w;
        cin >> w;

        if (w > 15000) {
            cout << "N ";
            continue;
        }

        int i;
        for (i = 0; i < N; ++i) {
            if (dp[i][w]) {
                cout << "Y ";
                break;
            }
        }

        if (i == N) {
            cout << "N ";
        }
    }
}
