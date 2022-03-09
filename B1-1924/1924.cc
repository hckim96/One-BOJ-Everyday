#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    vector<int> v(13, 30);
    v[0] = 0;
    v[2] = 28;
    v[1] = v[3] = v[5] = v[7] = v[8] = v[10] = v[12] = 31;
    int x, y;
    cin >> x >> y;

    for (int i = 1; i < 13; ++i) {
        v[i] += v[i - 1];
    }

    vector<string> ans = {
        "SUN",
        "MON",
        "TUE",
        "WED",
        "THU",
        "FRI",
        "SAT",
    };

    cout << ans[(v[x - 1] + y) % 7] << '\n';
}