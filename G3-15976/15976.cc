#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;
    vector<pair<int, int> > x(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i].first >> x[i].second;
    }

    int M;
    cin >> M;
    vector<int> pyIdx(M + 1);
    vector<int> py(M + 1, 0);
    int prevIdx = 0;
    for (int i = 0; i < M; ++i) {
        cin >> pyIdx[i + 1] >> py[i + 1];
        py[i + 1] += py[i];
        if (i == 0) pyIdx[i] = pyIdx[i + 1] - 1;
    }

    int a, b;
    cin >> a >> b;

    long long answer = 0;
    for (auto [xi, xv]: x) {
        auto it1 = lower_bound(pyIdx.begin(), pyIdx.end(), xi + b);
        auto it2 = lower_bound(pyIdx.begin(), pyIdx.end(), xi + a - 1);
        if (it1 == pyIdx.end() || (it1 != pyIdx.begin() && *it1 != xi + b)) --it1;
        if (it2 == pyIdx.end() || (it2 != pyIdx.begin() &&*it2 != xi + a - 1)) --it2;
        answer += 1LL * xv * (0LL + py[it1 - pyIdx.begin()] - py[it2 - pyIdx.begin()]);
    }
    cout << answer << '\n';
}