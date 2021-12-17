#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<long long> A(N), B(N);
    for (auto& e: A) cin >> e;
    for (auto& e: B) cin >> e;

    sort(all(A));
    sort(rall(B));

    long long answer = 0;

    for (int i = 0; i < N; ++i) {
        answer += A[i] * B[i];
    }
    cout << answer << '\n';
}