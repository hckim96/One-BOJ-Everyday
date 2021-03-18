#include <iostream>
#include <vector>

using namespace std;

int f(vector<int>& arr, vector<vector<vector<int> > >& dp, bool myTurn, int leftIdx, int rightIdx) {
    int& ret = dp[myTurn][leftIdx][rightIdx];

    if (leftIdx == rightIdx) {
        if (myTurn) {
            return ret = arr[leftIdx];
        } else {
            return ret = 0;
        }
    }

    if (ret != -1) {
        return ret;
    }

    if (myTurn) {
        return ret = max(arr[leftIdx] + f(arr, dp, !myTurn, leftIdx + 1, rightIdx), arr[rightIdx] + f(arr, dp, !myTurn, leftIdx, rightIdx - 1));
    } else {
        return ret = min(f(arr, dp, !myTurn, leftIdx + 1, rightIdx), f(arr, dp, !myTurn, leftIdx, rightIdx - 1));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> arr(N);

        for (auto & e: arr) {
            cin >> e;
        }

        vector<vector<vector<int> > > dp(2, vector<vector<int> > (N, vector<int> (N, -1)));

        cout << f(arr, dp, true, 0, N - 1) << '\n';
    }
}