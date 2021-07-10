#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(N);

    for (auto &e: arr) {
        cin >> e;
    }

    sort(arr.begin(), arr.end());

    for (auto e: arr) {
        cout << e << '\n';
    }
}
