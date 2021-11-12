#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int C;
    cin >> C;

    while (C--) {
        int N;
        cin >> N;

        vector<double> v(N);
        double sum = 0;
        for (int i = 0; i < N; ++i) {
            cin >> v[i];
            sum += v[i];
        }
        double avg = sum / N;
        double cnt = 0;
        for (int i = 0; i < N; ++i) {
            if (v[i] > avg) ++cnt;
        }

        cout.precision(3);
        cout << fixed << cnt / N * 100 << "%\n";
    }
}