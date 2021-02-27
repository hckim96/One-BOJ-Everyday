#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int> > arr(N + 1, vector<int> (N + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> arr[i][j];
            arr[i][j] = max(arr[i - 1][j - 1] + arr[i][j], arr[i - 1][j] + arr[i][j]);
        }
    }

    int answer = 0;

    for (int i = 1; i <= N; ++i) {
        answer = max(answer, arr[N][i]);
    }

    cout << answer << '\n';
}