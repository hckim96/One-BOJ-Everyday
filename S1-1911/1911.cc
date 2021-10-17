#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    long long N, L;
    cin >> N >> L;

    vector<pair<int, int> > v(N);

    for (auto& [s, e]: v) {
        cin >> s >> e;
    }

    sort(v.begin(), v.end());

    long long l, r;
    l = r = 0;
    long long answer = 0;
    for (auto [s, e]: v) {
        if (e <= r) continue;

        if (r <= s) {
            r = s;
        }
        long long tmp = (e - r) / L;
        if ((e - r) % L != 0) {
            ++tmp;
        }

        r += tmp * L;
        answer += tmp;
    }

    cout << answer << '\n';
}