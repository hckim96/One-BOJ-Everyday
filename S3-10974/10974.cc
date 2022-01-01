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
    for (int i = 0; i < N; ++i) {
        a[i] = i + 1;
    }

    vector<int> tmp(N), visited(N,false);

    function<void(int)> f = [&](int cur) {
        if (cur == N) {
            for (auto e: tmp) {
                cout << e << ' ';
            }
            cout << '\n';
            return;
        }

        for (int i = 0; i < N; ++i) {
            if (visited[i]) continue;
            visited[i] = true;
            tmp[cur] = a[i];
            f(cur + 1);
            visited[i] = false;
        }
    };

    f(0);
}