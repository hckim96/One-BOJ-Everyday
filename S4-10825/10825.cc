#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;
    vector<tuple<int, int, int, string> > v(N);
    for (auto& [a, b, c, d]: v) {
        cin >> d >> a >> b >> c;
        a *= -1;
        c *= -1;
    }
    sort(all(v));
    for (auto& [a, b, c, d]: v) {
        cout << d << '\n';
    }
}