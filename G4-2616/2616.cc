#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N_MAX 50000
int N, M;

vector<int> arr(N_MAX);
vector<vector<int> > dp(N_MAX, vector<int> (4, -1));

int f(int idx, int selectedNum) {
    if (selectedNum == 3) {
        return 0;
    }
    if (idx >= N - M + 1) {
        return 0;
    }

    if(dp[idx][selectedNum] != -1) {
        return dp[idx][selectedNum];
    }

    return dp[idx][selectedNum] = max(f(idx + 1, selectedNum), arr[idx + M - 1] - (idx == 0 ? 0 : arr[idx - 1]) + f(idx + M, selectedNum + 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (i > 0) {
            arr[i] += arr[i - 1];
        }
    }

    cin >> M;

    cout << f(0, 0) << "\n";
}