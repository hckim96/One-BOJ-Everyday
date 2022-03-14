#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    vector<int> v(9);
    for (auto& e: v) {
        cin >> e;
    }
    auto sum = accumulate(all(v), 0);

    vector<int> v2;
    for (int i = 0; i < 9; ++i) {
        for (int j = i + 1; j < 9; ++j) {
            if (100 == sum - v[i] - v[j]) {
                for (int k = 0; k < 9; ++k) {
                    if (k != i && k != j) {
                        v2.push_back(v[k]);
                    }
                }
                goto u;
            }
        }
    }
    u:;
    sort(all(v2));
    for (auto& e: v2) {
        cout << e << '\n';
    }
}