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

    int answer = 0;
    for (int i = 0; i < K; ++i) {
        answer += v[N - 1 - i] - i;
    }
    cout << answer << '\n';
}