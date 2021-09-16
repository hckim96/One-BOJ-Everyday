#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> v(N);

    for (auto& e: v) {
        cin >> e;
    }

    sort(v.begin(), v.end());

    int answer = v[v.size() - 1] - v[0];

    vector<int> v2(N - 1);

    for (int i = 0; i < N - 1; ++i) {
        v2[i] = v[i + 1] - v[i];
    }

    sort(v2.begin(), v2.end(), greater<int>());

    int iCnt = min(K - 1, N - 1);
    for (int i = 0; i < iCnt; ++i) {
        answer -= v2[i];
    }

    cout << answer << '\n';
}