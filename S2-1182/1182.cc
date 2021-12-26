#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    long long N, S;
    cin >> N >> S;

    vector<long long> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    long long answer = 0;
    function<void(int, long long)> f = [&](int cur, long long sum) {
        if (cur == N) {
            if (sum == S) {
                ++answer;
            }
            return;
        }


        f(cur + 1, sum);
        f(cur + 1, sum + a[cur]);
    };
    f(0, 0);
    cout << answer - (S == 0) << '\n';
}