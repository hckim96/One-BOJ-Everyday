#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<long long> v(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
    }

    int R;
    cin >> R;

    vector<vector<pair<int, long long> > > vv(N + 1); 
    while (R--) {
        long long a, b, d;
        cin >> a >> b >> d;
        vv[a].push_back({b, d});
    }

     priority_queue<pair<long long, int> > pq;

     for (int i = 1; i <= N; ++i) {
         pq.push({-v[i], i});
    }

    long long answer = 0;
    vector<int> learned(N + 1, false);
    while (M) {
        auto [c, i] = pq.top();
        c = -c;
        pq.pop();
        if (c > v[i]) continue;
        if (learned[i]) continue;

        learned[i] = true;
        answer = max(answer, c);
        --M;

        for (auto e: vv[i]) {
            v[e.first] -= e.second;
            pq.push({-v[e.first], e.first});
        }
    }
    cout << answer << '\n';
}
