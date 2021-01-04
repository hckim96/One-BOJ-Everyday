#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> > dp(41, {0, 0});

int T, N;

pair<int, int> countFib(int n) {
    if (dp[n].first != 0 || dp[n].second != 0) {
        return {dp[n].first, dp[n].second};
    }

    auto p1 = countFib(n - 1);
    auto p2 = countFib(n - 2);
    return dp[n] = {p1.first + p2.first, p1.second + p2.second};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    dp[0] = {1, 0};
    dp[1] = {0, 1};
    
    while (T--) {
        cin >> N;
        auto p = countFib(N);
        cout << p.first << " " << p.second << "\n";
    }
}