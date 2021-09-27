#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int main() {
    int N;
    cin >> N;

    vector<long long> v(6, 0);
    long long oneMin = INF;
    long long twoMin = INF;
    long long threeMin = INF;
    for (auto& e: v) {
        cin >> e;
        oneMin = min(oneMin, e);
    }

    long long answer = 0;

    if (N == 1) {
        long long sum = 0;
        long long max_ = 0;
        for (auto e: v) {
            max_ = max(max_, e);
            sum += e;
        }
        answer = sum - max_;
    } else {
        vector<long long> tmp = {min(v[0], v[5]), min(v[1], v[4]), min(v[2], v[3])};
        sort(tmp.begin(), tmp.end());
        twoMin = tmp[0] + tmp[1];
        threeMin = tmp[0] + tmp[1] + tmp[2];
        long long oneCnt, twoCnt, threeCnt;
        oneCnt = 5LL * (N - 2) * (N - 2) + 4 * (N - 2);
        twoCnt = 4LL + 8 * (N - 2);
        threeCnt = 4;

        answer = oneMin * oneCnt + twoMin * twoCnt + threeMin * threeCnt;
    }

    cout << answer << '\n';
}