#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    long long N, M;
    cin >> N >> M;

    vector<long long> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        if (i) a[i] += a[i - 1];
    }

    int i = 0;
    int j = 0;

    long long answer = 0;
    while (j < N) {
        long long sum = a[j];
        if (i) sum -= a[i - 1];

        if (sum > M) {
            ++i;
        } else if (sum < M) {
            ++j;
        } else {
            ++i;
            ++j;
            ++answer;
        }
    }
    cout << answer << '\n';
}