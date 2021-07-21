#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];

        if (i) {
            arr[i] += arr[i - 1];
        }
    }

    while (M--) {
        int i, j;
        cin >> i >> j;

        cout << arr[j - 1] - arr[i - 2] << '\n'; 
    }
}