#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> v(N, 0);
    
    for (auto& e: v) {
        cin >> e;
    }

    vector<int> LIS;
    for (auto e: v) {
        auto it = lower_bound(LIS.begin(), LIS.end(), e);
        if (it == LIS.end()) {
            LIS.push_back(e);
        } else {
            *it = e;
        }
    }

    cout << N - LIS.size() << '\n';
}