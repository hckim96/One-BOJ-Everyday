#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> LIS;

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;

        auto it = lower_bound(LIS.begin(), LIS.end(), num);

        if (it == LIS.end()) {
            LIS.push_back(num);
        } else {
            *it = num;
        }
    }

    cout << LIS.size() << '\n';
}
