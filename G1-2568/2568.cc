#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int> > arr(N);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end());

    vector<int> dp;
    vector<int> pos(N);

    for (int i = 0; i < N; ++i) {
        auto it = lower_bound(dp.begin(), dp.end(), arr[i].second);

        if (it == dp.end()) {
            pos[i] = dp.size();
            dp.push_back(arr[i].second);
        } else {
            pos[i] = it - dp.begin();
            *it = arr[i].second;
        }
    }

    cout << arr.size() - dp.size() << '\n';

    vector<int> seq;

    int idx = dp.size() - 1;

    for (int i = N - 1; i >= 0; --i) {
        if (idx == -1) {
            break;
        }

        if (pos[i] == idx) {
            seq.push_back(arr[i].first);
            --idx;
        }
    }

    idx = seq.size() - 1;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i].first != seq[idx]) {
            cout << arr[i].first << '\n';
        } else {
            --idx;
        }
    }
}
