#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(N);

    for (auto& e: arr) {
        cin >> e;
    }    

    vector<int> dp;

    auto it = dp.begin();

    for (auto e: arr) {
        it = lower_bound(dp.begin(), dp.end(), e);

        if (it == dp.end()) {
            dp.push_back(e);
        } else {
            *it = e;
        }
    }

    cout << dp.size() << '\n';
}