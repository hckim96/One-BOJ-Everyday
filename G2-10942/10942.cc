#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }

    vector<vector<bool> > dp(N + 2, vector<bool> (N + 2, true));

    for (int l = 0; l < N; ++l) {
        for (int s = 1; s <= N; ++s) {
            int e = s + l;
            if (e > N) {
                break;
            }
            
            dp[s][e] = dp[s + 1][e - 1] && (arr[s] == arr[e]);
        }
    }


    int M;
    cin >> M;

    while (M--) {
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << '\n';
    }

}