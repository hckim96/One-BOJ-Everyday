#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int K;
    cin >> K;
    int C;
    cin >> C;
    while (C--) {
        int M, N;
        cin >> M >> N;

        bool answer = false;

        if (M == N) {
            answer = true;
        } else if (M < N) {
            if (K - N + 1 >= N - M) {
                answer = true;
            }
        } else {
            if (K - M + 2 >= M - N) {
                answer = true;
            }
        }

        cout << answer << '\n';
    }
}