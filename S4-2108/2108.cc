#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(N);
    int sum = 0;
    vector<int> cnt(8001, 0);

    int maxCnt = 0;
    for (auto & e:arr) {
        cin >> e;
        maxCnt = max(maxCnt, ++cnt[e + 4000]);
        sum += e;
    }

    int mode = 0;

    for (int i = 0; i <= 8000; ++i) {
        if (cnt[i] == maxCnt) {
            if (mode) {
                mode = i - 4000;
                break;
            } else {
                mode = i - 4000;
            }
        }
    }

    sort(arr.begin(), arr.end());

    cout << round((double)sum / N) << '\n';
    cout << arr[N / 2] << '\n';
    cout << mode << '\n';
    cout << arr[N - 1] - arr[0] << '\n';
}
