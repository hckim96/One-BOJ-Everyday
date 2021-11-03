#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
    int N, K;
    cin >> N >> K;

    // time, money
    vector<pair<int, int> > walk(N);
    vector<pair<int, int> > bike(N);

    for (int i = 0; i < N; ++i) {
        cin >> walk[i].first >> walk[i].second >> bike[i].first >> bike[i].second;
    }

    int answer = 0;

    vector<vector<int> > maxMoney(N + 1, vector<int> (K + 1, 0));
    maxMoney[1][walk[0].first] = max(maxMoney[1][walk[0].first], walk[0].second);
    maxMoney[1][bike[0].first] = max(maxMoney[1][bike[0].first], bike[0].second);
    for (int i = 2; i <= N; ++i) {
        for (int k = 0; k <= K; ++k) {
            if (maxMoney[i - 1][k] == 0) continue;
            if (walk[i - 1].first + k <= K) maxMoney[i][k + walk[i - 1].first] = max(maxMoney[i][k + walk[i - 1].first], maxMoney[i - 1][k] + walk[i - 1].second);
            if (bike[i - 1].first + k <= K) maxMoney[i][k + bike[i - 1].first] = max(maxMoney[i][k + bike[i - 1].first], maxMoney[i - 1][k] + bike[i - 1].second);
        }
    }
    for (int k = 0; k <= K; ++k) {
        answer = max(answer, maxMoney[N][k]);
    }
    cout << answer << '\n';
}