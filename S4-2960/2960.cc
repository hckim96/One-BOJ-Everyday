#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, K;
    cin >> N >> K;

    vector<int> isp(N + 1, true);

    for (int i = 2; i <= N; ++i) {
        if (!isp[i])continue;
        isp[i] = false;
        if (!--K) {
            cout << i << '\n';
            return 0;
        }

        for (int j = i * i; j <= N; j += i) {
            if (!isp[j]) continue;
            
            if (!--K) {
                cout << j << '\n';
                return 0;
            }
            isp[j] = false;
        }
    }
}