#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    vector<int> v(3);
    for (auto& e: v) {
        cin >> e;
    }

    sort(all(v));
    cout << v[1] << '\n';
}