#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;
    vector<int> A(N);
    for (auto& e: A) cin >> e;

    sort(all(A));
    int x;
    cin >> x;
    int i = 0;
    int j = N - 1;

    int answer = 0;
    while (i < j) {
        if (A[i] + A[j] == x) {
            ++answer;
            ++i;
        } else if (A[i] + A[j] < x) {
            ++i;
        } else {
            --j;
        }
    }

    cout << answer << '\n';
}