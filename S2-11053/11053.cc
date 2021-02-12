#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> arr(N);

    for (auto & e: arr) {
        cin >> e;
    }

    vector<int> last;

    for (int i = 0; i < N; ++i) {
        auto it = lower_bound(last.begin(), last.end(), arr[i]);
        if (it == last.end()) {
            last.push_back(arr[i]);
        } else {
            *it = arr[i];
        }
    }

    cout << last.size() << '\n';
}
