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

    vector<long long> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    sort(rall(a));

    long long answer = 0;
    long long min_ = 1e18;
    for (int i = 0; i < N; ++i) {
        min_ = min(min_, a[i]);
        answer = max(answer, min_ * (i + 1));
    }
    cout << answer << '\n';
}