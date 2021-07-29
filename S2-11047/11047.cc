#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int answer = 0;

    for (int i = N - 1; i >= 0; --i) {
        if (K == 0) {
            break;
        }

        if (K >= arr[i]) {
            answer += K / arr[i];
            K %= arr[i];
        }
    }

    cout << answer << '\n';
}