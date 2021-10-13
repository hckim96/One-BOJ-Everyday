#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> v(N);
    vector<int> sum(N, 0);

    for (int i = 0; i < N; ++i) {
        cin >> v[i];
        if (i) sum[i] = sum[i - 1] + v[i];
        else sum[i] = v[i];
    }

    int answer = 0;
    for (int i = 1; i < N - 1; ++i) {
        int v1 = 2 * sum[N - 1] - v[0] - (v[i] + sum[i]);
        int v2 = sum[N - 1] - v[N - 1] - 2 * v[i] + sum[i];
        int v3 = sum[N - 2] - v[0] + v[i];
        answer = max(answer, v1);
        answer = max(answer, v2);
        answer = max(answer, v3);
    }
    cout << answer << '\n';
}