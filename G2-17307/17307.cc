#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    long long C;
    cin >> N >> C;

    vector<long long> color(N);

    for (auto& e: color) cin >> e;

    // left, right
    vector<pair<long long, long long> > pCost(N, {0, 0});
    for (int i = 0; i < N; ++i) {

        pair<long long, long long> cost = {0, 0};

        if (i) cost.first = (C + color[i - 1] - color[i]) % C;
        if (i + 1 < N) cost.second = (C + color[i + 1] - color[i]) % C;

        if (i) pCost[i] = pCost[i - 1];
        pCost[i].first += cost.first;
        pCost[i].second += cost.second;
    }

    long long answer = 1e18;
    long long answerBtn = 0;

    for (int i = 0; i < N; ++i) {
        long long tmp;

        tmp = max(pCost[i].first, pCost[N - 1].second - (i - 1 >= 0 ? pCost[i - 1].second : 0));
        if (answer > tmp) {
            answerBtn = i + 1;
            answer = tmp;
        }
    }

    cout << answerBtn << '\n';
    cout << answer << '\n';
}