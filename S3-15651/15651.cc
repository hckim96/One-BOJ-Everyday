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

    vector<int> seq;
    function<void(int)> f = [&](int cnt) {
        if (cnt == 0) {
            for (auto e: seq) {
                cout << e << ' ';
            }
            cout << '\n';
            return;
        }

        for (int i = 1; i <= N; ++i) {
            seq.push_back(i);
            f(cnt - 1);
            seq.pop_back();
        }
    };

    f(M);
}
