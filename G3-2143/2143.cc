#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, N, M;
    cin >> T;
    cin >> N;
    vector<long long> A(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    cin >> M;
    vector<long long> B(M + 1, 0);
    for (int i = 1; i <= M; ++i) {
        cin >> B[i];
    }

    vector<long long> sumA;
    vector<long long> sumB;

    for (int i = 1; i <= N; ++i) {
        long long sum = A[i];
        sumA.push_back(sum);
        for (int j = i + 1; j <= N; ++j) {
            sum += A[j];
            sumA.push_back(sum);
        }
    }
    for (int i = 1; i <= M; ++i) {
        long long sum = B[i];
        sumB.push_back(sum);
        for (int j = i + 1; j <= M; ++j) {
            sum += B[j];
            sumB.push_back(sum);
        }
    }

    sort(sumA.begin(), sumA.end());
    sort(sumB.begin(), sumB.end());

    auto it = sumA.begin();

    long long answer = 0;

    while (it != sumA.end()) {
        auto next = upper_bound(sumA.begin(), sumA.end(), *it);
        long long cnt = next - lower_bound(sumA.begin(), sumA.end(), *it);

        long long cnt2 = upper_bound(sumB.begin(), sumB.end(), T - *it) - lower_bound(sumB.begin(), sumB.end(), T - *it);

        answer += cnt * cnt2;
        it = next;
    }

    cout << answer << '\n';

}