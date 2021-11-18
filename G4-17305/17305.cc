#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, W;
    cin >> N >> W;
    
    vector<int> v3, v5;
    for (int i = 0; i < N; ++i) {
        int w, s;
        cin >> w >> s;

        if (w == 3) {
            v3.push_back(s);
        } else {
            v5.push_back(s);
        }
    }

    sort(all(v3), greater<int>());
    sort(all(v5), greater<int>());
    vector<long long> pv3(v3.size(), 0), pv5(v5.size(), 0);
    for (int i = 0; i < pv3.size(); ++i) {
        pv3[i] = v3[i];
        if (i) pv3[i] += pv3[i - 1];
    }
    for (int i = 0; i < pv5.size(); ++i) {
        pv5[i] = v5[i];
        if (i) pv5[i] += pv5[i - 1];
    }

    long long answer = 0;

    int j = min(W / 5, (int)v5.size());
    while (j >= 0) {
        int i = min((W - 5 * j) / 3, (int)v3.size());
        long long tmp = 0;
        if (i) tmp += pv3[i - 1];
        if (j) tmp += pv5[j - 1];
        answer = max(answer, tmp);
        --j;
    }
    cout << answer << '\n';
}