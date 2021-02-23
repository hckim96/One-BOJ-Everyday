#include <iostream>
#include <vector>
#include <algorithm>

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

    sort(arr.begin(), arr.end());

    int sum = 0;

    for (auto e: arr) {
        if (sum + 1 < e) {
            break;
        }
        sum += e;
    }

    cout << sum + 1 << '\n';
}
