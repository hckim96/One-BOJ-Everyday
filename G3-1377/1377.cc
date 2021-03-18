#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int> > arr(N);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());

    int max_ = 0;
    for (int i = 0; i < N; ++i) {
        max_ = max(max_, arr[i].second - i);
    }

    cout << max_ + 1 << '\n';
}