#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;
    vector<int> a(N);
    for (auto& e: a) {
        cin >> e;
    }

    int answer = -1e9;
    vector<int> tmp(N);
    vector<int> visited(N, 0);

    function<void(int)> f = [&](int cur) {
        if (cur == N) {
            int sum = 0;
            for (int i = 0; i < N - 1; ++i) {
                sum += abs(tmp[i] - tmp[i + 1]);
            }
            answer = max(answer, sum);
            return;
        }


        for (int i = 0; i < N; ++i) {
            if (visited[i]) continue;
            tmp[cur] = a[i];
            visited[i] = true;
            f(cur + 1);
            visited[i] = false;
        }
    };
    f(0);
    cout << answer << '\n';
}