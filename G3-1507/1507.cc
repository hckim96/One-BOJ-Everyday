#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int> > cost(N + 1, vector<int> (N + 1, 0));

    int answer = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> cost[i][j];
            if (i < j) {
                answer += cost[i][j];
            }
        }
    }

    vector<vector<bool> > checked(N + 1, vector<bool> (N + 1, false));

    for (int j = 1; j <= N; ++j) {
        for (int i = 1; i <= N; ++i) {
            for (int k = i + 1; k <= N; ++k) {
                if (i == j || j == k) {
                    continue;
                }
                if (checked[i][k]) {
                    continue;
                }

                if (cost[i][k] == cost[i][j] + cost[j][k]) {
                    answer -= cost[i][k];
                    checked[i][k] = true;
                } else if (cost[i][k] > cost[i][j] + cost[j][k]) {
                    answer = -1;
                    cout << answer << '\n';
                    return 0;
                }
            }
        }
    }

    cout << answer << '\n';
}